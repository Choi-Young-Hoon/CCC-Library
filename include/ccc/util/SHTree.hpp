#ifndef __UTIL_STRING_HASH_TREE_HEADER__
#define __UTIL_STRING_HASH_TREE_HEADER__

#include <iostream>

namespace ccc_define {
	enum __NODE_DIRECTION {
		DIRECTION_RIGHT = 0,
		DIRECTION_LEFT,
		DIRECTION_CENTER
	};		
	typedef enum __NODE_DIRECTION NODE_DIRECTION;


	enum __NODE_FUNC_OPTION {
		OPTION_NEXT_NODE_ALLOC,
		OPTION_NEXT_NODE_NON_ALLOC
	};
	typedef enum __NODE_FUNC_OPTION NODE_FUNC_OPTION;
};



namespace ccc {

	/********************************
	 * String hash base search Tree
	 ********************************/
	template <typename DATA_TYPE>
	class SHTree {
	public: // Member Class
		class SHNode {
		public: 
			explicit SHNode()
			: m_pLeft(NULL), m_pCenter(NULL), m_pRight(NULL)
			, m_bEndFlag(false)
			, m_NodeData(0)
			{}
			virtual ~SHNode()
			{}


		public:
			static SHNode* Create(const char data) {
				SHNode* pNode = new SHNode;
				if (pNode == NULL) {
					// ....
					throw -1;
				}

				pNode->m_NodeData = data;
				return pNode;
			}



		public:
			void SetNextNode(ccc_define::NODE_DIRECTION direction, const char data) {
				SHNode* pNode = SHNode::Create(data);

				switch (direction) {
				case ccc_define::DIRECTION_RIGHT:
					if (m_pRight != NULL)
						delete m_pRight;
					m_pRight = pNode;
					break;

				case ccc_define::DIRECTION_LEFT:
					if (m_pLeft != NULL) 
						delete m_pLeft;
					m_pLeft = pNode;
					break;

				case ccc_define::DIRECTION_CENTER:
					if (m_pCenter != NULL) 
						delete m_pCenter;
					m_pCenter = pNode;
					break;
				}
			}


		public:
			DATA_TYPE m_Value;

			bool m_bEndFlag;
			char m_NodeData;
			
			SHNode* m_pLeft;
			SHNode* m_pCenter;
			SHNode* m_pRight;
		};

	
	public:
		explicit SHTree()
		: m_pNodeHead(NULL)
		{}
		virtual ~SHTree()
		{}


	public: // Functional
		bool Insert(const std::string& strHash, const DATA_TYPE& data) {
			if (m_pNodeHead == NULL) 
				m_pNodeHead = SHNode::Create(strHash[0]);
			
			if (Find(strHash)) 
				return false;

			SHNode* pNode = m_pNodeHead;
			for (unsigned int i = 0; i < strHash.length(); i++) {
				GetNextNode(strHash[i], ccc_define::OPTION_NEXT_NODE_ALLOC, &pNode);
			}

			pNode->m_bEndFlag = true;
			pNode->m_Value    = data;
			return true;
		}


		bool Find(const std::string& strHash) noexcept {
			SHNode* pNode = m_pNodeHead;

			for (unsigned int i = 0; i < strHash.length(); i++) {
				if (!GetNextNode(strHash[i], ccc_define::OPTION_NEXT_NODE_NON_ALLOC, &pNode)) 
					return false;
			}

			return pNode->m_bEndFlag;
		}


		bool GetData(const std::string& strHash, DATA_TYPE* pData) {
		
			return true;
		}


		void Update(const std::string& strHash) {
			
		}


		void Delete(const std::string& strHash) {
		
		}


		void Clear() noexcept {
			
		}


	protected:
		ccc_define::NODE_DIRECTION CheckNodeDirection(SHNode* pNode, const char value) {
			ccc_define::NODE_DIRECTION retVal;
			const char nodeData = pNode->m_NodeData;
			
			if 		(nodeData < value) 
				retVal = ccc_define::DIRECTION_RIGHT;
			else if (nodeData > value) 
				retVal = ccc_define::DIRECTION_LEFT;
			else // (nodeData == value) 
				retVal = ccc_define::DIRECTION_CENTER;

			return retVal;
		}


		bool GetNextNode(const char value, ccc_define::NODE_FUNC_OPTION option, SHNode** ppNode) {
			SHNode* pTargetNode = *ppNode;

			SHNode** ppNextNode = NULL;	
			
			
			ccc_define::NODE_DIRECTION direction = CheckNodeDirection(pTargetNode, value);
			switch (direction) {
			case ccc_define::DIRECTION_RIGHT:
				ppNextNode = &pTargetNode->m_pRight;
				break;

			case ccc_define::DIRECTION_LEFT:
				ppNextNode = &pTargetNode->m_pLeft;
				break;

			case ccc_define::DIRECTION_CENTER:
				ppNextNode = &pTargetNode->m_pCenter;
				break;	
			}


			if (*ppNextNode == NULL && option == ccc_define::OPTION_NEXT_NODE_ALLOC) 
				pTargetNode->SetNextNode(direction, value);


			if (*ppNextNode == NULL)
				return false;
			
			*ppNode = *ppNextNode;
			return true;
		}


	private: // Member Valiable
		SHNode* m_pNodeHead; // Root Node
	};


};

#endif
