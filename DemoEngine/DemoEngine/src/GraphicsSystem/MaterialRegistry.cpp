#include "MaterialRegistry.h"
#include <cassert>

#include "ShaderRegistry.h"
#include "TextureRegistry.h"

namespace lge
{
	//
	// Static Data
	//

	MaterialRegistry* MaterialRegistry::singletonInstance = nullptr;



	//
	// Methods
	//

	MaterialRegistry::MaterialRegistry() :
		materialList()
	{
		assert(MaterialRegistry::singletonInstance == nullptr);
		MaterialRegistry::singletonInstance = this;
	}

	// VIRTUAL
	MaterialRegistry::~MaterialRegistry()
	{
		// List must be emptied before destroying manager!
		assert(this->materialList.GetNumberOfElements() == 0);

		// Manager must exist in singleton link!
		assert(MaterialRegistry::singletonInstance != nullptr);
		MaterialRegistry::singletonInstance = this;
	}


	// VIRTUAL
	void MaterialRegistry::Load()
	{
		Material* mat1 = MaterialRegistry::Create(MaterialName::Material1,
												  ShaderName::DiffuseTexture,
												  PolygonModeType::FullFace,
												  TextureName::Duckweed);

		Material* mat3 = MaterialRegistry::Create(MaterialName::Material3,
												  ShaderName::BlinnPhong,
												  PolygonModeType::FullFace);

		Material* mat5 = MaterialRegistry::Create(MaterialName::Material5,
												  ShaderName::NormalDiffuseTexture,
												  PolygonModeType::FullFace,
												  TextureName::Rocks);

		Material* proc1 = MaterialRegistry::Create(MaterialName::ProceduralSurfaceSimple,
												  ShaderName::DiffuseTexture,
												  PolygonModeType::FullFace,
												  TextureName::ProceduralSurfaceSimple);

		Material* proc2 = MaterialRegistry::Create(MaterialName::ProceduralSurfaceMinimal,
												   ShaderName::DiffuseTexture,
												   PolygonModeType::FullFace,
												   TextureName::ProceduralSurfaceMinimal);

		Material* proc3 = MaterialRegistry::Create(MaterialName::ProceduralSurfaceComplicated,
												   ShaderName::DiffuseTexture,
												   PolygonModeType::FullFace,
												   TextureName::ProceduralSurfaceComplicated);


		MaterialRegistry::Create(MaterialName::Material2,
								 ShaderName::ConstantTexture,
								 PolygonModeType::FullFace,
								 TextureName::MarioGround);

		MaterialRegistry::Create(MaterialName::Material4,
								 ShaderName::VertexRainbow,
								 PolygonModeType::Wireframe);




		const Vect theLightPosition(0.0f, 0.0f, 0.0f);
		const Vect phongTintColor(0.0f, 0.5f, 1.0f);
		const Vect diffuseLightColor(1.0f, 1.0f, 1.0f);
		const Vect specularLightColor(1.0f, 1.0f, 1.0f);
		const Vect blackColor(0.0f, 0.0f, 0.0f);
		const float specularPower = 100.0f;
		

		// Uniform customization
		mat1->SetUniform(UniformName::LightPosition, theLightPosition);
		mat1->SetUniform(UniformName::LightColor, diffuseLightColor);


		mat3->SetUniform(UniformName::TintColor, phongTintColor);
		mat3->SetUniform(UniformName::SpecularColor, specularLightColor);
		mat3->SetUniform(UniformName::SpecularPowerFloat, specularPower);
		mat3->SetUniform(UniformName::LightPosition, theLightPosition);
		mat3->SetUniform(UniformName::LightColor, diffuseLightColor);


		mat5->SetTexture(&TextureRegistry::Find(TextureName::ExampleNormalMap));
		mat5->SetUniform(UniformName::TintColor, diffuseLightColor);
		mat5->SetUniform(UniformName::SpecularColor, blackColor);
		mat5->SetUniform(UniformName::SpecularPowerFloat, 1.0f);
		mat5->SetUniform(UniformName::LightPosition, theLightPosition);
		mat5->SetUniform(UniformName::LightColor, diffuseLightColor);


		proc1->SetUniform(UniformName::TintColor, diffuseLightColor);
		proc1->SetUniform(UniformName::LightPosition, theLightPosition);
		proc1->SetUniform(UniformName::LightColor, diffuseLightColor);


		proc2->SetUniform(UniformName::TintColor, diffuseLightColor);
		proc2->SetUniform(UniformName::LightPosition, theLightPosition);
		proc2->SetUniform(UniformName::LightColor, diffuseLightColor);


		proc3->SetUniform(UniformName::TintColor, diffuseLightColor);
		proc3->SetUniform(UniformName::LightPosition, theLightPosition);
		proc3->SetUniform(UniformName::LightColor, diffuseLightColor);
	}


	// VIRTUAL
	void MaterialRegistry::Unload()
	{
		while (this->materialList.GetNumberOfElements() != 0)
		{
			Material* oldObject = this->materialList.RemoveFront();
			delete oldObject;
		}
	}


	// VIRTUAL
	void MaterialRegistry::Update()
	{
		// Intentionally does nothing
	}




	// STATIC
	// Must be dynamically allocated, for it will be deleted by this manager later
	void MaterialRegistry::Add(Material* newObject)
	{
		assert(newObject != nullptr);
		MaterialRegistry::singletonInstance->materialList.AddFront(newObject);
	}

	// STATIC
	// Find any Material
	Material& MaterialRegistry::Find(MaterialName name)
	{
		return *(MaterialRegistry::singletonInstance->materialList.FindById(static_cast<unsigned int>(name)));
	}



	// STATIC
	// Factory for Material. Automatically added
	Material* const MaterialRegistry::Create(MaterialName newName, ShaderName shaderName, PolygonModeType polygonMode)
	{
		assert(MaterialRegistry::singletonInstance != nullptr);

		Material* newMaterial = new Material(&ShaderRegistry::Find(shaderName),
											 polygonMode,
											 newName);

		MaterialRegistry::Add(newMaterial);

		return newMaterial;

	}
	
	// STATIC
	// Factory for Material. Automatically added. Also adds a color map texture
	Material* const MaterialRegistry::Create(MaterialName newName, ShaderName shaderName, PolygonModeType polygonMode, TextureName textureName)
	{
		Material* newMaterial = MaterialRegistry::Create(newName, shaderName, polygonMode);

		newMaterial->SetTexture(&TextureRegistry::Find(textureName));

		return newMaterial;
	}



}