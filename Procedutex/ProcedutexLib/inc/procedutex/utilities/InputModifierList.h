#pragma once
#include "procedutex\elements\InputModifier.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// A Collection of utility classes for any Modifier
	namespace modutil
	{
		// A Linked List of InputModifier instances
		class InputModifierList
		{

			///////////////
			// Begin Nested Classes
			///////////////

			private:

				// The internal node of InputModifierList
				class Node
				{
				public:
					Node();
					Node(inmods::abstract::InputModifier* const newModifier);
					Node(inmods::abstract::InputModifier* const newModifier, Node* const nextNode, Node* const previousNode);
					~Node();

					Node* const GetNext() const;
					Node* const GetPrev() const;
					inmods::abstract::InputModifier* const GetModifier() const;

					void SetNext(Node* const newNext);
					void SetPrev(Node* const newPrev);
					void SetModifier(inmods::abstract::InputModifier* const newModifier);


				private:

					Node* next;
					Node* prev;
					inmods::abstract::InputModifier* modifier;

				};

			public:

				// The iterator of InputModifierList
				class Iterator
				{
				public:
					// No default Ctor
					Iterator() = delete;
					// Ctor only to be used by the list class
					Iterator(Node* const headNode);
					// Copy Ctor
					Iterator(const Iterator& other);
					// No assignment
					Iterator& operator=(const Iterator& other) = delete;
					// Dtor
					~Iterator();


					// Get the first modifier in this iterator's list
					inmods::abstract::InputModifier* const GetFirst() const;
					
					// Go to next modifier without returning
					void GoToNext();
					
					// Return the current modifier
					inmods::abstract::InputModifier* const GetCurrent() const;
					
					// Move iterator back to beginning
					void Reset();
					
					// Returns true if the iterator cannot continue
					const bool IsDone() const;

				private:

					Node* const first;
					Node* current;
				};





			///////////////
			// Begin List Class
			///////////////

		public:

			//
			// Ctor / Dtor
			//

			InputModifierList();
			~InputModifierList();
			

			//
			// Methods
			//

			void AddToBack(inmods::abstract::InputModifier* const newModifier);
			const unsigned int GetNumberOfItems() const;
			Iterator GetIterator() const;
			void Clear();



		private:

			//
			// Data
			//

			Node* head;
			Node* tail;
			unsigned int numNodes;

			
			
			//
			// Private Routines
			//
			
			void AddNodeToBack(Node* const newNode);
			void RemoveNodeOnBack();

		};
	}
}