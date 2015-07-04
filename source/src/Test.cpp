#include "../inc/Test.h"



void Test::testSqList() {
    cout << "顺序表测试开始……" << endl;
    SqListElemType list[] = { 1, 2, 3, 4 };
    int size = sizeof(list) / sizeof(int);
    for (int i = 0; i < size; ++i)
        sqList.insertElem(list[i], i);
    sqList.show();
    sqList.insertElem(3, 2);
    sqList.show();
    sqList.deleleElem(2);
    sqList.show();
    sqList.replaceElem(3, 1);
    sqList.show();
    sqList.traverse(SqList::visit);
    sqList.show();
    cout << endl;
}

void Test::testLinkList() {
    cout << "链表测试开始……" << endl;
    LinkListElemType list[] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(LinkListElemType);
    for (int i = 0; i < size; ++i)
        linkList.insertTailElem(list[i]);
    linkList.show();
    for (int i = 0; i < size; ++i)
        linkList.insertHeadElem(list[i]);
    linkList.show();
    for (int i = 0; i < size; ++i)
        linkList.insertElem(list[i], i * 2);
    linkList.show();
    linkList.deleteHeadElem();
    linkList.deleteTailElem();
    linkList.show();
    //linkList.init();
    //linkList.show();
    //linkList.insertHeadElem(1);
    //linkList.show();
    //linkList.deleteHeadElem();
    //linkList.show();
    //linkList.insertTailElem(1);
    //linkList.show();
    //linkList.deleteTailElem();
    //linkList.show();
    linkList.deleteElem(0);
    linkList.deleteElem(linkList.getLength() - 1);
    linkList.show();
    linkList.deleteElem(2);
    linkList.show();
    linkList.replaceElem(9, 1);
    linkList.show();
    cout << "index :" << linkList.getIndex(9) << "   data: " << linkList.getElem(linkList.getIndex(9)) << endl;
    linkList.traverse(LinkList::visit);
    linkList.show();
    cout << endl;
}

void  Test::testStack() {
    cout << "栈测试开始……" << endl;
    StackElemType list[3] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(StackElemType);
    stack.push(1);
    stack.show();
    cout << "栈顶元素：" << stack.getTop() << endl;
    stack.pop();
    stack.show();
    for (int i = 0; i < size; ++i)
        stack.push(list[i]);
    stack.show();
    stack.pop();
    stack.traverse(Stack::visit);
    stack.show();
    cout << endl;
}

void Test::testQueue() {
    cout << "队列测试开始……" << endl;
    QueueElemType list[3] = { 1, 2, 3 };
    int size = sizeof(list) / sizeof(QueueElemType);
    queue.enQueue(1);
    queue.show();
    cout << "队首元素：" << queue.getHead() << endl;
    queue.deQueue();
    queue.show();
    for (int i = 0; i < size; ++i)
        queue.enQueue(list[i]);
    queue.show();
    queue.deQueue();
    stack.traverse(Queue::visit);
    queue.show();
}

void Test::testBinaryTree() {
    cout << "二叉树测试开始……" << endl;
    BiTreeElemType pre_data[MAXELEMNUM], in_data[MAXELEMNUM], post_data[MAXELEMNUM], elem_data[MAXELEMNUM];
    cout << "二叉树创建并显示……" << endl;
    biTree.createBibaryTree(biTree.getRootPoint(), NULL);
    biTree.show(0);
    int i, nums;
    for (i = 0;; ++i) {
        fin >> pre_data[i];
        if (!pre_data[i]) {
            nums = i;
            break;
        }
    }
    for (i = 0; i <= nums; ++i)
        fin >> in_data[i];
    for (i = 0; i <= nums; ++i)
        fin >> post_data[i];
    biTree.init();
    cout << "先序、中序创建二叉树并显示……" << endl;
    biTree.show(0);
    biTree.preinCreateBinaryTree(biTree.getRootPoint(), NULL, pre_data, in_data, nums);
    biTree.show(0);
    cout << "后序、中序创建二叉树并显示……" << endl;
    BinaryTree *ptrBiTree = new BinaryTree();
    ptrBiTree->postinCreateBinaryTree(ptrBiTree->getRootPoint(), NULL, post_data, in_data, nums);
    ptrBiTree->show(0);
    delete ptrBiTree;
    int depth, allNodeNums, leafNodeNums;
    biTree.getNodeInfo(depth, allNodeNums, leafNodeNums);
    cout << "二叉树信息：depth(" << depth << ") allNums(" << allNodeNums << ") leafNums(" << leafNodeNums << ")……" << endl;
    BiTreeElemType data = 4;
    BiNode *node = biTree.findNode(data);
    cout << "获取值为4的结点，元素为：" << biTree.getNodeData(node);
    biTree.setNodeData(node, 8);
    cout << ", 设置为新值后为：" << biTree.getNodeData(node) << endl;
    biTree.show(0);
    LR lr;
    BiNode *newNode = biTree.getNodeSibling(node, lr);
    cout << "元素：" << biTree.getNodeData(node) << "的结点为：" << lr << "结点，兄弟结点元素为：" << biTree.getNodeData(newNode) << endl;
    biTree.insertChildNode(biTree.getRoot(), LEFT, 4);
    biTree.insertChildNode(biTree.getRoot(), RIGHT, 9);
    biTree.show(0);
    biTree.getNodeInfo(depth, allNodeNums, leafNodeNums);
    cout << "二叉树信息：depth(" << depth << ") allNums(" << allNodeNums << ") leafNums(" << leafNodeNums << ")……" << endl;
    biTree.deleteChildNode(node, LEFT);
    biTree.show(0);
    biTree.getNodeInfo(depth, allNodeNums, leafNodeNums);
    cout << "二叉树信息：depth(" << depth << ") allNums(" << allNodeNums << ") leafNums(" << leafNodeNums << ")……" << endl;
    BiTreeElemType *base = elem_data;
    biTree.preOrderTraverse(BinaryTree::visit, &base);
    cout << "先序遍历结果：";
    for (i = 0; i < allNodeNums; ++i)
        cout << elem_data[i] << " ";
    cout << endl;
    base = elem_data;
    biTree.inOrderTraverse(BinaryTree::visit, &base);
    cout << "中序遍历结果：";
    for (i = 0; i < allNodeNums; ++i)
        cout << elem_data[i] << " ";
    cout << endl;
    base = elem_data;
    biTree.postOrderTraverse(BinaryTree::visit, &base);
    cout << "后序遍历结果：";
    for (i = 0; i < allNodeNums; ++i)
        cout << elem_data[i] << " ";
    cout << endl;
    biTree.levelOrderTraverse(BinaryTree::visit, elem_data);
    cout << "后序遍历结果：";
    for (i = 0; i < allNodeNums; ++i)
        cout << elem_data[i] << " ";
    cout << endl;
}

void Test::testTree() {
    cout << "树的测试开始……" << endl;
    tree.createTree();
    tree.show();
    //tree.init();
    //tree.show();
    UInt8 depth, all_nums, leaf_nums;
    tree.getTreeInfo(depth, all_nums, leaf_nums);
    cout << "树的结点信息：depth(" << (UInt32)depth << ") all_nums(" << (UInt32)all_nums << ") leaf_nums(" << (UInt32)leaf_nums << ")" << endl;
    TreeNode* tree_node = tree.getRoot();
    TreeElemType node_data = tree.getNodeData(tree_node);
    tree.setNodeData(tree_node, node_data + 1);
    TreeNode* child_node = tree.getChild(tree_node, 2);
    TreeNode* sbling_node = tree.getSbling(child_node, LEFT);
    TreeNode* parent_node = tree.getParent(sbling_node);
    UInt8 child_index = tree.getChildIndex(parent_node, 4);
    cout << "结点相关操作信息：" << node_data << " " << tree.getNodeData(child_node) << " " << tree.getNodeData(sbling_node) << " " << tree.getNodeData(parent_node) << " " << (UInt32)child_index << endl;
    tree.setNodeData(parent_node, 1);
    tree.show();
    tree.InsertChild(child_node, 8);
    tree.InsertChild(sbling_node, 9);
    //tree.show();
    tree.deleteChild(sbling_node, 1);
    //tree.show();
    tree.deleteNode(tree.getSbling(child_node, RIGHT));
    tree.show();
    TreeElemType data[MAXELEMNUM];
    tree.BFSTraverse(Tree::visit, data);
    all_nums = tree.getNodeNums();
    cout << "BFS遍历的结果为：";
    for (UInt8 i = 0; i < all_nums; ++i) {
        cout << data[i] << " ";                    
    }
    cout << endl;
    tree.DFSTraverse(Tree::visit, data);
    cout << "DFS遍历的结果为：";
    for (UInt8 i = 0; i < all_nums; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void Test::testDGraph() {
    cout << "有向图测试开始：" << endl;
    d_graph.createGraph();
    d_graph.show();
    d_graph.init();
    d_graph.show();
    d_graph.createGraph();
    d_graph.show();
    GType   type = d_graph.getType();
    UInt32  vex_nums = d_graph.getVexNums();
    UInt32  arc_nums = d_graph.getArcNums();
    bool    is_empty = d_graph.isEmpty();
    cout << "有向图的基本信息：type(" << type << ") vex_nums(" << vex_nums << ") arc_nums(" << arc_nums << ") empty(" << is_empty << ")" << endl;
    VexType ori_data = 'C', new_data = 'E';
}

void Test::testUDGraph() {
    cout << "无向图测试开始：" << endl;
    ud_graph.createGraph();
    ud_graph.show();
    ud_graph.init();
    ud_graph.show();
    ud_graph.createGraph();
    ud_graph.show();
    GType   type = ud_graph.getType();
    UInt32  vex_nums = ud_graph.getVexNums();
    UInt32  arc_nums = ud_graph.getArcNums();
    bool    is_empty = ud_graph.isEmpty();
    cout << "无向图的基本信息：type(" << type << ") vex_nums(" << vex_nums << ") arc_nums(" << arc_nums << ") empty(" << is_empty << ")" << endl;
    VexType ori_data = 'C', new_data = 'E';
    UVex* vex = ud_graph.locateVex(ori_data);
    ori_data = ud_graph.getVexData(vex);
    ud_graph.setVexData(vex, new_data);
    new_data = ud_graph.getVexData(vex);
    UVex *first_vex, *second_vex;
    VexType first_data, second_data;
    first_vex = ud_graph.firstVex(vex);
    second_vex = ud_graph.nextVex(vex, first_vex);
    first_data = ud_graph.getVexData(first_vex);
    second_data = ud_graph.getVexData(second_vex);
    cout << "顶点操作：" << ori_data << " " << new_data << " " << first_data << " " << second_data << endl;
    UVex* new_vex = ud_graph.insertVex(ori_data);
    ud_graph.show();
    ud_graph.insertArc(new_vex, vex, 3);
    ud_graph.insertArc(new_vex, first_vex, 5);
    ud_graph.insertArc(new_vex, second_vex, 4);
    ud_graph.deleteArc(first_vex, second_vex);
    ud_graph.show();
    UVex* delete_vex = ud_graph.locateVex('B');
    ud_graph.deleteVex(delete_vex);
    ud_graph.show();
    cout << "深度遍历结果：";
    ud_graph.DFSTraverse(UDGraph::visit);
    cout << endl << "宽度遍历结果：";
    ud_graph.BFSTraverse(UDGraph::visit);
    cout << endl;
}