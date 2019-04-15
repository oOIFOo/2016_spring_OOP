#include "mySystem_2048.h"
#include <iostream>

using namespace std;

MY_2048::MY_2048( )
{
    mNX = 4;
    mNZ = 4;
    reset( );

    mPositionX = 0;
    mPositionZ = 0;
    mFlgFocus = true;
}

void MY_2048::setFocus( bool flg )
{
    mFlgFocus = flg;
}

void MY_2048::setPosition( int x, int z )
{
    mPositionX = x;
    mPositionZ = z;
}

//
// copy the board of m to this object
//
void MY_2048::copy( const BASE_SYSTEM *m )
{
	const MY_2048 *x = dynamic_cast<const MY_2048 * >(m);
    // Implement your own stuff
	for (int i = 0; i < mNX; i++){
		for (int j = 0; j < mNZ; j++){
			mBoard[j][i] = x->mBoard[j][i];
		}
	}
	//const MY_2048 *x = dynamic_cast<const MY_2048 * >(m);
}


void MY_2048::reset( )
{
	int a;
    for ( int j = 0; j < mNZ; ++j ) {
        for ( int i = 0; i < mNX; ++i ) {\
			a = (rand() % 2) + 1;
			a = a * 2;
			mBoard[j][i] = a;
        }
    }
    //mNumFreeCells = mNX * mNZ;
    mEvent = 0;
}

void MY_2048::askForInput( )
{
	cout << "MY_2048" << endl;
	cout << "Key usage:" << endl;
	cout << "1: generate randomly the numbers 2 and 4 for all the cells" << endl;
	cout << "2: generate randomly the numbers 2, 4 and 8 for all the cells" << endl;
	cout << "3: generate randomly the numbers for all the cells" << endl;
	cout << "r: clear all the cells" << endl;
	cout << " " << endl;
	cout << "UP, DOWN, LEFT, RIGHT: move the numbers to the respective side" << endl;

}

//
// Generate a new number (2 or 4) randomly.
//
void MY_2048::generateNumber( )
{
	int a;
	srand(time(NULL));
	a = (rand() % 2) + 1;
	a = a * 2;
}

void MY_2048::moveDown( )
{
	for (int i = 0; i < mNX; i++){
		for (int z = 0; z <= mNZ - 1; z++){
			if (mBoard[z][i] == 0)	continue;
			for (int j = 1;; j++){
				if (z + j == mNZ){
					break;
				}
				if (mBoard[z][i] == mBoard[z + j][i]){
					mBoard[z][i] *= 2;
					mBoard[z + j][i] = 0;
					break;
				}
				if (mBoard[z + j][i] != 0){
					break;
				}
			}
		}
/********************************************************************************/
		for (int z = 0; z <= mNZ - 1; z++){
			if (mBoard[z][i] == 0){
				for (int j = 1; z + j <= mNZ - 1; j++){
					if (mBoard[z + j][i] != 0){
						mBoard[z][i] = mBoard[z + j][i];
						mBoard[z + j][i] = 0;
						break;
					}
				}
			}
		}
	}

	int com = 0;
	for (int y = mNZ - 1; y >= 0; y--){
		for (int x = 0; x <= mNX - 1; x++){
			if (mBoard[y][x] == 0){
				int a = 0;
				a = (rand() % 2) + 1;
				a = a * 2;
				mBoard[y][x] = a;
				com = 1;
				break;
			}
		}
		if (com == 1){
			break;
		}
	}
}

void MY_2048::moveUp( )
{
	for (int i = 0; i < mNX; i++){
		for (int z = mNZ - 1; z >= 0; z--){
			for (int j = 1;; j++){
				if (z - j == -1){
					break;
				}
				if (mBoard[z][i] == mBoard[z - j][i]){
					mBoard[z][i] *= 2;
					mBoard[z - j][i] = 0;
					break;
				}
				if (mBoard[z - j][i] != 0){
					break;
				}
			}
		}

		for (int z = mNZ - 1; z >= 0; z--){
			if (mBoard[z][i] == 0){
				for (int j = 1; z - j >= 0; j++){
					if (mBoard[z - j][i] != 0){
						mBoard[z][i] = mBoard[z - j][i];
						mBoard[z - j][i] = 0;
						break;
					}
				}
			}
		}
	}


	int com = 0;
	for (int y = mNZ - 1; y >= 0; y--){
		for (int x = 0; x <= mNX - 1; x++){
			if (mBoard[y][x] == 0){
				int a = 0;
				a = (rand() % 2) + 1;
				a = a * 2;
				mBoard[y][x] = a;
				com = 1;
				break;
			}
		}
		if (com == 1){
			break;
		}
	}
}

void MY_2048::moveLeft( )
{
	for (int z = 0; z < mNZ; z++){
		for (int i = 0; i <= mNX - 1; i++){
			if (mBoard[z][i] == 0)	continue;
			for (int j = 1;; j++){
				if (i + j == mNX){
					break;
				}
				if (mBoard[z][i] == mBoard[z][i + j]){
					mBoard[z][i] *= 2;
					mBoard[z][i + j] = 0;
					break;
				}
				if (mBoard[z][i + j] != 0){
					break;
				}
			}
		}
		/********************************************************************************/
		for (int i = 0; i <= mNX - 1; i++){
			if (mBoard[z][i] == 0){
				for (int j = 1; i + j <= mNX - 1; j++){
					if (mBoard[z][i + j] != 0){
						mBoard[z][i] = mBoard[z][i + j];
						mBoard[z][i + j] = 0;
						break;
					}
				}
			}
		}
	}


	int com = 0;
	for (int y = mNZ - 1; y >= 0; y--){
		for (int x = 0; x <= mNX - 1; x++){
			if (mBoard[y][x] == 0){
				int a = 0;
				a = (rand() % 2) + 1;
				a = a * 2;
				mBoard[y][x] = a;
				com = 1;
				break;
			}
		}
		if (com == 1){
			break;
		}
	}
}

void MY_2048::moveRight( )
{
	for (int z = 0; z < mNZ; z++){
		for (int i = mNX - 1; i >= 0; i--){
			for (int j = 1;; j++){
				if (i - j == -1){
					break;
				}
				if (mBoard[z][i] == mBoard[z][i - j]){
					mBoard[z][i] *= 2;
					mBoard[z][i - j] = 0;
					break;
				}
				if (mBoard[z][i - j] != 0){
					break;
				}
			}
		}

		for (int i = mNX - 1; i >= 0; i--){
			if (mBoard[z][i] == 0){
				for (int j = 1; i - j >= 0; j++){
					if (mBoard[z][i - j] != 0){
						mBoard[z][i] = mBoard[z][i - j];
						mBoard[z][i - j] = 0;
						break;
					}
				}
			}
		}
	}


	int com = 0;
	for (int y = mNZ - 1; y >= 0; y--){
		for (int x = 0; x <= mNX - 1; x++){
			if (mBoard[y][x] == 0){
				int a = 0;
				a = (rand() % 2) + 1;
				a = a * 2;
				mBoard[y][x] = a;
				com = 1;
				break;
			}
		}
		if (com == 1){
			break;
		}
	}
}

void MY_2048::generateNumbers_All_2to4( )
{
    reset( );
	int a;
	for (int i = 0; i < mNX; i++){
		for (int z = 0; z < mNZ; z++){
			a = (rand() % 2) + 1;
			a = a * 2;
			mBoard[z][i] = a;
		}
	}
    //
    // Implement your own stuff
    //
}

void MY_2048::generateNumbers_All_2to8( )
{
    reset( );
	int a;
	for (int i = 0; i < mNX; i++){
		for (int z = 0; z < mNZ; z++){
			a = (rand() % 3) + 1;
			if (a == 3){
				a = 8;
			}
			else{
				a = a * 2;
			}
			mBoard[z][i] = a;
		}
	}
    //
    // Implement your own stuff
    //
}

void MY_2048::generateNumbers_All( )
{
    reset( );
	int a;
	for (int i = 0; i < mNX; i++){
		for (int z = 0; z < mNZ; z++){
			a = (rand() % 10) + 1;
			a = pow(2 , a);
			mBoard[z][i] = a;
		}
	}
    // Implement your own stuff
    //
}

void MY_2048::handleKeyPressedEvent( unsigned char key )
{
    switch( key ) {
    case 'r':
    case 'R':
        reset( );
        break;
    case '1':
		//cout << "*********************************" << endl;
        generateNumbers_All_2to4( );
        break;
    case '2':
        generateNumbers_All_2to8( );
        break;
    case '3':
        generateNumbers_All( );
        break;
    }
}

void MY_2048::handleSpecialKeyPressedEvent( unsigned char key )
{
    //cout << "MY_2048::handleSpecialKeyPressedEvent:" << key << endl;
    bool flgDone = false;

    switch( key ) {
    case GLUT_KEY_UP:
        flgDone = true;
        moveUp( );
        mEvent = GLUT_KEY_UP;
        break;
    case GLUT_KEY_DOWN:
        flgDone = true;
        moveDown( );
        mEvent = GLUT_KEY_DOWN;

        break;
    case GLUT_KEY_LEFT:
        flgDone = true;
        moveLeft( );
        mEvent = GLUT_KEY_LEFT;

        break;
    case GLUT_KEY_RIGHT:
        flgDone = true;
        moveRight( );
        mEvent = GLUT_KEY_RIGHT;

        break;

    }
    //
    // Implement your own stuff
    //
}
