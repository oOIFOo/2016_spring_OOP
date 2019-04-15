//********************************************
// Student Name			:
// Student ID			:
// Student Email Address:
//********************************************
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2016/02/27
//
#ifndef __MY_SYSTEM_APP_APP_H_
#define __MY_SYSTEM_APP_APP_H_
/////////////////////////////////////////////
#include "../headers.h"
#include <string>
#include "../openGLbasic/opengl_stuff.h"
#include "../freeCanvas2D/freeCanvas2D.h"
#include "../textureManager/texture.h"
/////////////////////////////////////////////
#include "mySystem_MonteCarlo.h"
#include "mySystem_QuadraticFunction.h"
#include "mySystem_CubicFunction.h"
#include "mySystem_StudentRecordManager.h"

#define SYSTEM_TYPE_MONTE_CARLO_CIRCLE		1
#define SYSTEM_TYPE_QUADRATIC_FUNCTION		2
#define SYSTEM_TYPE_CUBIC_FUNCTION			3
#define SYSTEM_TYPE_STUDENT_RECORD_MANAGER	4

/////////////////////////////////////////////

using namespace ns_opengl;
class MY_SYSTEM_APP : public FREE_CANVAS_2D
{
protected:
	bool mFlgShow_Grid;
	int mMouseButton;
	//
	void drawOrigin( ) const;
	void draw_MonteCarlo_Circle( ) const;
	void draw_System_Content( ) const;
	void draw_QuadraticFunction( ) const;
	void draw_CubicFunction( ) const;
	void draw_StudentRecordManager( ) const;
	void askForInput( );
	//
	void showStudentInfo( ) const;
public:
	MY_SYSTEM_APP( );
	virtual void update( );
	virtual void draw( ) const;
	virtual void initApp( );
	//
	bool specialFunc(int key, int x, int y);
	bool handleKeyEvent( unsigned char key );
	bool passiveMouseFunc( int mx, int my );
	bool mouseMotionFunc( int x, int y );
	bool mouseFunc( int button, int state, int x, int y );
	//////////////////////////////////////////////////
protected:
	int mSystemType;
	MONTE_CARLO_SYSTEM mMonteCarloSystem;
	QUADARTIC_FUNCTION mQuadraticFunction;
	CUBIC_FUNCTION mCubicFunction;
	STUDENT_RECORD_MANAGER mStudentRecordManager;
};

#endif