#include <iostream>
#include "mySystem_GraphSystem.h"

using namespace std;

GRAPH_SYSTEM::GRAPH_SYSTEM( )
{
    //
    // Implement your own stuff
	reset();
    createDefaultGraph();
	//system("pause");
	//cout << "***************************************************" << endl;
}

void GRAPH_SYSTEM::reset( )
{

    //
    // Implement your own stuff
    //
    mPassiveSelectedNode = 0;
    mSelectedNode = 0;
	mnodes.clear();
	medge.clear();
	alive.clear();
	//cout << "***************************************************" << endl;
}

void GRAPH_SYSTEM::createDefaultGraph( )
{
    reset( );

    int n_0 = addNode( 0.0, 0.0, 0.0 );
    int n_1 = addNode( 5.0, 0.0, 0.0 );
    int n_2 = addNode( 0.0, 0.0, 5.0 );
    addEdge( n_0, n_1 );
    addEdge( n_1, n_2 );
}

void GRAPH_SYSTEM::createNet_Horizontal( int nx, int ny )
{
    reset( );
	//int n_0 = addNode(0.0, 0.0, 0.0);
	int x;
    float dx = 5.0; // spacing along the x-axis
    float dz = 5.0; // spacing along the y-axis
	float tmp_x, tmp_z;
	for (int i = 0; i < nx; i++){
		for (int j = 0; j < ny; j++){
			tmp_x = dx*i;
			tmp_z = dz*j;
			//x = addNode(tmp_x, 0.0, tmp_z);
			addNode(0.0, 0.0, 0.0);
		}
	}
}

void GRAPH_SYSTEM::createNet_Vertical( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    //
    // Implement your own stuff
	int x;
	float tmp_x, tmp_z;
	for (int i = 0; i < nx; i++){
		for (int j = 0; j < ny; j++){
			tmp_x = dx*i;
			tmp_z = dz*j;
			//x = addNode(tmp_x, 0.0, tmp_z);
			addNode(0.0, 0.0, 0.0);
		}
	}
}

void GRAPH_SYSTEM::createRandomGraph( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    //
    // Implement your own stuff
	int x;
	float tmp_x, tmp_z;
	for (int i = 0; i < nx; i++){
		for (int j = 0; j < ny; j++){
			tmp_x = dx*i;
			tmp_z = dz*j;
			//x = addNode(tmp_x, 0.0, tmp_z);
			addNode(0.0, 0.0, 0.0);
		}
	}
}

void GRAPH_SYSTEM::createRadialGraph( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    //
    // Implement your own stuff
	int x;
	float tmp_x, tmp_z;
	for (int i = 0; i < nx; i++){
		for (int j = 0; j < ny; j++){
			tmp_x = dx*i;
			tmp_z = dz*j;
			//x = addNode(tmp_x, 0.0, tmp_z);
			addNode(0.0, 0.0, 0.0);
		}
	}
}

int GRAPH_SYSTEM::addNode( float x, float y, float z, float r )
{
    //
    // Implement your own stuff
	GRAPH_NODE tmp;
	tmp.p = vector3(x, y, z);
	tmp.r = r;
	tmp.id = mnodes.size();
	mnodes.push_back(tmp);
	return tmp.id;
}

int GRAPH_SYSTEM::addEdge( int nodeID_0, int nodeID_1 )
{
    //
    // Implement your own stuff
	GRAPH_EDGE tmp;
	tmp.nodeID[0] = nodeID_0;
	tmp.nodeID[1] = nodeID_1;
	tmp.id = medge.size();
	medge.push_back(tmp);
	return tmp.id;
}

void GRAPH_SYSTEM::askForInput( )
{
	cout << "GRAPH_SYSTEM" << endl;
	cout << "Key usage:" << endl;
	cout << "1: create a default graph" << endl;
	cout << "2: create a graph with 10x10 nodes. Connect the consecutive nodes horizontally" << endl;
	cout << "3: create a graph with 10x10 nodes. Connect the consecutive nodes vertically" << endl;
	cout << "4: create a graph with 10x10 nodes. Create 10 randomly generated edges" << endl;
	cout << "5: create a graph with 10x10 nodes. Create 10 randomly generated edges attached at a random node" << endl;
	cout << "Delete: delete a node and all the edges attached at it" << endl;
	cout << "Spacebar: unselect the selected node" << endl;
	cout << " " << endl;
	cout << "Use the mouse to select nodes and add edges" << endl;
	cout << "Click the left button to select/unselect or create an edge" << endl;
	cout << " " << endl;
	cout << "A selected node is highlighted as red." << endl;

}

// Find the nearest node to the given position (x, y, z).
// Note that we work in x-z plane only. y should be set to 0.
// The squared distance of the node and the given position should be stored in cur_distance2.
//
//
GRAPH_NODE *GRAPH_SYSTEM::findNearestNode( double x, double z, double &cur_distance2 ) const
{
    GRAPH_NODE *n = 0;
    //
    // Implement your own stuff
    //
    /*
    cur_distance2 = -1.0;
    for ( int i = 0; i < mCurNumOfActiveNodes; ++i ) {
    int id = mActiveNodeArr[ i ];
    const GRAPH_NODE *cn = &mNodeArr_Pool[ id ];
    double dx = cn->p.x - x;
    double dz = cn->p.z - z;
    double d2 = dx*dx + dz*dz;
    if ( cur_distance2 < 0.0 || d2 < cur_distance2 ) {
    cur_distance2 = d2;
    n = (GRAPH_NODE *)cn;
    }

    }
    */
    return n;
}

void GRAPH_SYSTEM::clickAt(double x, double z)
{
    double cur_d2;
    GRAPH_NODE *n = findNearestNode( x, z, cur_d2 );
    if ( n == 0 ) {
        mSelectedNode = 0;
        return;
    }
    //
    // A nearest node may not be touched by the mouse cursor.
    // Thus we need their distance to check.
    //
    if ( cur_d2 > n->r*n->r ) {
        mSelectedNode = 0;
        return;

    }
    if ( mSelectedNode == n ) {
        mSelectedNode = 0;
        return;
    }
    if ( mSelectedNode != 0 ) {
        addEdge( mSelectedNode->id, n->id );
        mSelectedNode = 0;
        return;
    }
    mSelectedNode = n;
}

void GRAPH_SYSTEM::deleteNode( int nodeID ) {
    //
    // Implement your own stuff
	if (mSelectedNode == 0) return;
	mnodes.erase(mnodes.begin() + nodeID);
}

void GRAPH_SYSTEM::deleteSelectedNode(  ) {
    if ( mSelectedNode == 0 ) return;
    deleteNode( mSelectedNode->id );
    //
    // Implement your own stuff
    //
    // for examples,
    // delete edges attached at the node
    //
    //
    mSelectedNode = 0;
    mPassiveSelectedNode = 0;
}

bool GRAPH_SYSTEM::isSelectedNode( ) const
{
    return mSelectedNode != 0;
}

void GRAPH_SYSTEM::getInfoOfSelectedPoint( double &r, vector3 &p ) const
{
    if ( isSelectedNode( ) == false ) return;
    r = mSelectedNode->r;
    p = mSelectedNode->p;

}

void GRAPH_SYSTEM::handleKeyPressedEvent( unsigned char key )
{
	cout << "handleKeyPressedEventvhandleKeyPressedEventhandleKeyPressedEventhandleKeyPressedEvent" << endl;
    switch( key ) {
    case 127: // delete
        deleteSelectedNode( );
        break;
    case '1':
        createDefaultGraph( );
        mSelectedNode = 0;
        break;
    case '2':
		cout << "***************************************************" << endl;
        createNet_Horizontal(10, 10);
        mSelectedNode = 0;

        break;
    case '3':
        createNet_Vertical(10, 10);
        mSelectedNode = 0;

        break;
    case '4':
        createRandomGraph(10, 10);
        mSelectedNode = 0;

        break;
    case '5':
        createRadialGraph(10, 10);
        mSelectedNode = 0;

        break;
    case ' ':
        mSelectedNode = 0;
        break;
    }
}

void GRAPH_SYSTEM::handlePassiveMouseEvent( double x, double z )
{
    double cur_d2;
    GRAPH_NODE *n = findNearestNode( x, z, cur_d2 );
    if ( n == 0 ) return;
    if ( cur_d2 > n->r*n->r ) {
        mPassiveSelectedNode = 0;
        return;
    }
    mPassiveSelectedNode = n;
}

int GRAPH_SYSTEM::getNumOfNodes( ) const
{
    //
    // Implement your own stuff
	return mnodes.size(); // remove this line
}

void GRAPH_SYSTEM::getNodeInfo( int nodeIndex, double &r, vector3 &p ) const
{

    //
    // Implement your own stuff
	r = mnodes[nodeIndex].r;
	p = mnodes[nodeIndex].p;
}

int GRAPH_SYSTEM::getNumOfEdges( ) const
{
    //
    // Implement your own stuff
    //
	return medge.size(); // remove this line
}

vector3 GRAPH_SYSTEM::getNodePositionOfEdge( int edgeIndex, int nodeIndex ) const
{
    //
    // Implement your own stuff
	int tmp;
	vector3 tmp1;
	tmp = medge[edgeIndex].nodeID[nodeIndex];
	tmp1 = mnodes[tmp].p;
    return tmp1; // remove this line
}
