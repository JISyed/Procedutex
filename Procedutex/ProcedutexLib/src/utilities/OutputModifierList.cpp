#include "procedutex\utilities\OutputModifierList.h"
#include <cassert>

namespace procedutex
{
	namespace modutil
	{
		//
		// Node
		//

		OutputModifierList::Node::Node() :
			next(nullptr),
			prev(nullptr),
			modifier(nullptr)
		{
		}

		OutputModifierList::Node::Node(outmods::abstract::OutputModifier* const newModifier) :
			next(nullptr),
			prev(nullptr),
			modifier(newModifier)
		{
		}

		OutputModifierList::Node::Node(outmods::abstract::OutputModifier* const newModifier, Node* const nextNode, Node* const previousNode) :
			next(nextNode),
			prev(previousNode),
			modifier(newModifier)
		{
		}

		OutputModifierList::Node::~Node()
		{
			if (this->modifier != nullptr)
			{
				delete this->modifier;
			}
		}

		OutputModifierList::Node* const OutputModifierList::Node::GetNext() const
		{
			return this->next;
		}

		OutputModifierList::Node* const OutputModifierList::Node::GetPrev() const
		{
			return this->prev;
		}

		outmods::abstract::OutputModifier* const OutputModifierList::Node::GetModifier() const
		{
			return this->modifier;
		}


		void OutputModifierList::Node::SetNext(OutputModifierList::Node* const newNext)
		{
			this->next = newNext;
		}

		void OutputModifierList::Node::SetPrev(OutputModifierList::Node* const newPrev)
		{
			this->prev = newPrev;
		}

		void OutputModifierList::Node::SetModifier(outmods::abstract::OutputModifier* const newModifier)
		{
			this->modifier = newModifier;
		}




		//
		// Iterator
		//


		OutputModifierList::Iterator::Iterator(OutputModifierList::Node* const headNode) :
			first(headNode),
			current(headNode)
		{
		}

		OutputModifierList::Iterator::Iterator(const Iterator& other) :
			first(other.first),
			current(other.current)
		{
		}

		OutputModifierList::Iterator::~Iterator()
		{
		}

		outmods::abstract::OutputModifier* const OutputModifierList::Iterator::GetFirst() const
		{
			return this->first->GetModifier();
		}

		void OutputModifierList::Iterator::GoToNext()
		{
			this->current = this->current->GetNext();
		}

		outmods::abstract::OutputModifier* const OutputModifierList::Iterator::GetCurrent() const
		{
			return this->current->GetModifier();
		}

		void OutputModifierList::Iterator::Reset()
		{
			this->current = this->first;
		}

		const bool OutputModifierList::Iterator::IsDone() const
		{
			return this->current == nullptr;
		}





		//
		// List
		//

		OutputModifierList::OutputModifierList() :
			head(nullptr),
			tail(nullptr),
			numNodes(0u)
		{
		}

		OutputModifierList::~OutputModifierList()
		{
			this->Clear();
		}


		void OutputModifierList::AddToBack(outmods::abstract::OutputModifier* const newModifier)
		{
			OutputModifierList::Node* newNode = new OutputModifierList::Node(newModifier);
			this->AddNodeToBack(newNode);
		}

		const unsigned int OutputModifierList::GetNumberOfItems() const
		{
			return this->numNodes;
		}

		OutputModifierList::Iterator OutputModifierList::GetIterator() const
		{
			return Iterator(this->head);
		}

		void OutputModifierList::Clear()
		{
			while (this->head != nullptr)
			{
				this->RemoveNodeOnBack();
			}
		}

		void OutputModifierList::AddNodeToBack(OutputModifierList::Node* const newNode)
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

		void OutputModifierList::RemoveNodeOnBack()
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