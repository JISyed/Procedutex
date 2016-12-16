#include "MeshRenderer.h"
#include "Camera.h"

#include "GL\gl3w.h"
#include "Mesh.h"
#include "MathEngine.h"
#include "Material.h"


namespace lge
{
	MeshRenderer::MeshRenderer(Material* const newMaterial, Mesh* const newMesh, const Matrix& gameObjectTransform) :
		sharedMaterial(newMaterial),
		sharedMesh(newMesh)
	{
		this->modelMatrix = new Matrix();
		*(this->modelMatrix) = gameObjectTransform;
	}

	// VIRTUAL
	// Dtor
	MeshRenderer::~MeshRenderer()
	{
		this->sharedMaterial = nullptr;
		this->sharedMesh = nullptr;
		delete this->modelMatrix;
	}




	void MeshRenderer::SetModelMatrix(const Matrix& gameObjectMatrix)
	{
		*(this->modelMatrix) = gameObjectMatrix;
	}

	void MeshRenderer::SetMaterial(Material * const newMaterial)
	{
		this->sharedMaterial = newMaterial;
	}

	void MeshRenderer::SetMesh(Mesh * const newMesh)
	{
		this->sharedMesh = newMesh;
	}




	// VIRTUAL
	// Setting states in OpenGL
	void MeshRenderer::SetState()
	{
		glEnable(GL_CULL_FACE);
		glFrontFace(GL_CW);

		this->sharedMaterial->SetPolygonRenderState();
	}

	// VIRTUAL
	// Sending data to the GPU if needed
	void MeshRenderer::SetGpuData()
	{
		// set the vao
		this->sharedMesh->MakeActiveMesh();

		// Setup the projection matrix
		this->sharedMaterial->SetUniform(UniformName::ProjectionMatrix, Camera::GetActiveCamera().GetProjection());

		// Get the view matrix
		this->sharedMaterial->SetUniform(UniformName::ViewMatrix, Camera::GetActiveCamera().GetView());

		// Set the model matrix
		this->sharedMaterial->SetUniform(UniformName::ModelMatrix, *(this->modelMatrix));


		// use this Material (and its shader), will automagiacally send uniforms into the shader and GPU
		this->sharedMaterial->MakeActive();

		
	}

	// VIRTUAL
	// Actual draw call
	void MeshRenderer::Render()
	{
		// Draw
		glDrawElements(GL_TRIANGLES, this->sharedMesh->GetNumberOfTriangles() * 3, GL_UNSIGNED_INT, 0);
	}

	// VIRTUAL
	// Restoring states back to prevent unexpected rendering behavior
	void MeshRenderer::RestoreState()
	{
		this->sharedMaterial->RestorePolygonRenderState();

		glEnable(GL_CULL_FACE);
		glFrontFace(GL_CW);
	}




}