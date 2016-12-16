#include "procedutex\utilities\InputModifierList.h"
#include <cassert>

namespace procedutex
{
	namespace modutil
	{
		//
		// Node
		//

		InputModifierList::Node::Node() :
			next(nullptr),
			prev(nullptr),
			modifier(nullptr)
		{
		}

		InputModifierList::Node::Node(inmods::abstract::InputModifier* const newModifier) :
			next(nullptr),
			prev(nullptr),
			modifier(newModifier)
		{
		}

		InputModifierList::Node::Node(inmods::abstract::InputModifier* const newModifier, Node* const nextNode, Node* const previousNode) :
			next(nextNode),
			prev(previousNode),
			modifier(newModifier)
		{
		}

		InputModifierList::Node::~Node()
		{
			if (this->modifier != nullptr)
			{
				delete this->modifier;
			}
		}

		InputModifierList::Node* const InputModifierList::Node::GetNext() const
		{
			return this->next;
		}

		InputModifierList::Node* const InputModifierList::Node::GetPrev() const
		{
			return this->prev;
		}

		inmods::abstract::InputModifier* const InputModifierList::Node::GetModifier() const
		{
			return this->modifier;
		}


		void InputModifierList::Node::SetNext(InputModifierList::Node* const newNext)
		{
			this->next = newNext;
		}

		void InputModifierList::Node::SetPrev(InputModifierList::Node* const newPrev)
		{
			this->prev = newPrev;
		}

		void InputModifierList::Node::SetModifier(inmods::abstract::InputModifier* const newModifier)
		{
			this->modifier = newModifier;
		}




		//
		// Iterator
		//


		InputModifierList::Iterator::Iterator(InputModifierList::Node* const headNode) :
			first(headNode),
			current(headNode)
		{
		}

		InputModifierList::Iterator::Iterator(const Iterator& other) :
			first(other.first),
			current(other.current)
		{
		}

		InputModifierList::Iterator::~Iterator()
		{
		}

		inmods::abstract::InputModifier* const InputModifierList::Iterator::GetFirst() const
		{
			return this->first->GetModifier();
		}

		void InputModifierList::Iterator::GoToNext()
		{
			this->current = this->current->GetNext();
		}

		inmods::abstract::InputModifier* const InputModifierList::Iterator::GetCurrent() const
		{
			return this->current->GetModifier();
		}

		void InputModifierList::Iterator::Reset()
		{
			this->current = this->first;
		}

		const bool InputModifierList::Iterator::IsDone() const
		{
			return this->current == nullptr;
		}





		//
		// List
		//

		InputModifierList::InputModifierList() :
			head(nullptr),
			tail(nullptr),
			numNodes(0u)
		{
		}

		InputModifierList::~InputModifierList()
		{
			this->Clear();
		}


		void InputModifierList::AddToBack(inmods::abstract::InputModifier* const newModifier)
		{
			InputModifierList::Node* newNode = new InputModifierList::Node(newModifier);
			this->AddNodeToBack(newNode);
		}

		const unsigned int InputModifierList::GetNumberOfItems() const
		{
			return this->numNodes;
		}

		InputModifierList::Iterator InputModifierList::GetIterator() const
		{
			return Iterator(this->head);
		}

		void InputModifierList::Clear()
		{
			while (this->head != nullptr)
			{
				this->RemoveNodeOnBack();
			}
		}

		void InputModifierList::AddNodeToBack(InputModifierList::Node* const newNode)
		{
			if (this->head == nullptr)
			{
				assert(this->numNodes == 0u);
				assert(this->tail == nullptr);
				this->head = newNode;
				this->tail = newNode;
				this->head->SetNext(nullptr);
				this->head->SetPrev(nullptr);
			}
			else
			{
				if (this->numNodes == 1u)
				{
					this->tail = newNode;
					this->tail->SetNext(nullptr);
					this->tail->SetPrev(this->head);
					this->head->SetNext(this->tail);
				}
				else
				{
					this->tail->SetNext(newNode);
					newNode->SetPrev(this->tail);
					this->tail = newNode;
				}
			}

			this->numNodes++;
		}

		void InputModifierList::RemoveNodeOnBack()
		{
			assert(this->numNodes > 0u);
			assert(this->head != nullptr);
			assert(this->tail != nullptr);

			if (this->head == this->tail)
			{
				Node* toBeRemoved = this->head;
				this->head = nullptr;
				this->tail = nullptr;
				delete toBeRemoved;
			}
			else
			{
				assert(this->numNodes >= 2u);
				if (this->numNodes == 2u)
				{
					Node* toBeRemoved = this->tail;
					assert(this->head->GetNext() == this->tail);
					this->head->SetNext(nullptr);
					this->tail = this->head;
					delete toBeRemoved;
				}
				else
				{
					assert(this->head->GetNext() != this->tail);
					Node* toBeRemoved = this->tail;
					this->tail->GetPrev()->SetNext(nullptr);
					this->tail = toBeRemoved->GetPrev();
					delete toBeRemoved;
				}
			}

			this->numNodes--;
		}




	}
}