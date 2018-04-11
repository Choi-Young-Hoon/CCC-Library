#ifndef __UTIL_STRING_HASH_TREE_HEADER__
#define __UTIL_STRING_HASH_TREE_HEADER__

#include <iostream>



namespace ccc {

	/********************************
	 * String hash base search Tree
	 ********************************/
	template <typename DATA_TYPE>
	class StringHashTree {
	public:
		explicit StringHashTree();
		virtual ~StringHashTree();
	

	public: // Functional
		

	private:
	 	/*********************
		 * Tree Node
		 *********************/
		class TreeNode {
		public: 
			explicit TreeNode()
			: m_pLeft(NULL), m_pCenter(NULL), m_pRight(NULL)
			, m_bEndFlag(false)
			, m_NodeData(0)
			{}
			virtual ~TreeNode()
			{}

		public:
			DATA_TYPE m_Value;

			bool m_bEndFlag;
			char m_NodeData;
			
			TreeNode* m_pLeft,
					* m_pCenter,
					* m_pRight;
		};
		TreeNode* m_pTreeHead; // Root Node



		/**********************
		 * Tree Info
		 **********************/
		class TreeInfo {
		public:
			explicit TreeInfo()
			: m_nNodeCount(0), m_nItemCount(0)
			{}
			virtual ~TreeInfo()
			{}

		public:
			int m_nItemCount;	// Number of Elements
			int m_nNodeCount;	// Number of Node
		};	
		TreeInfo m_TreeInfo; // This Hash Tree class Info
		

	};

};
#endif
