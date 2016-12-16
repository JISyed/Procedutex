#pragma once
#include "procedutex\elements\OutputModifier.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// A Collection of utility classes for any Modifier
	namespace modutil
	{
		class OutputModifierList
		{
			///////////////
			// Begin Nested Classes
			///////////////

		private:

			// The internal node of OutputModifierList
			class Node
			{
			public:
				Node();
				Node(outmods::abstract::OutputModifier* const newModifier);
				Node(outmods::abstract::OutputModifier* const newModifier, Node* const nextNode, Node* const previousNode);
				~Node();

				Node* const GetNext() const;
				Node* const GetPrev() const;
				outmods::abstract::OutputModifier* const GetModifier() const;

				void SetNext(Node* const newNext);
				void SetPrev(Node* const newPrev);
				void SetModifier(outmods::abstract::OutputModifier* const newModifier);


			private:

				Node* next;
				Node* prev;
				outmods::abstract::OutputModifier* modifier;

			};

		public:

			// The iterator of OutputModifierList
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
				outmods::abstract::OutputModifier* const GetFirst() const;

				// Go to next modifier without returning
				void GoToNext();

				// Return the current modifier
				outmods::abstract::OutputModifier* const GetCurrent() const;

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

			OutputModifierList();
			~OutputModifierList();


			//
			// Methods
			//

			void AddToBack(outmods::abstract::OutputModifier* const newModifier);
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