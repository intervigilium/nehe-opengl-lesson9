/* 	GLTutorial.java
 *  
 *	Copyright (c) 2010 Ethan Chen
 *	
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *	
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *	THE SOFTWARE.
 */

package com.intervigil.gltest;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class GLTutorial extends Activity {
	
	private static final String NDK_LIB = "gltutorial";
	private static final String CLASS_NAME = "GLTutorial";

	private TutorialView mGLSurfaceView;
	
	static {
		System.loadLibrary(NDK_LIB);
	}
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
    	Log.i(CLASS_NAME, "onCreate()");
        super.onCreate(savedInstanceState);
        
        mGLSurfaceView = new TutorialView(GLTutorial.this);
        setContentView(mGLSurfaceView);
    }
    
    @Override
    protected void onDestroy() {
    	Log.i(CLASS_NAME, "onDestroy()");
    	super.onDestroy();
    	mGLSurfaceView.onDestroy();
    }
    
    @Override
    protected void onPause() {
    	Log.i(CLASS_NAME, "onPause()");
    	super.onPause();
    	mGLSurfaceView.onPause();
    }
    
    @Override
    protected void onResume() {
    	Log.i(CLASS_NAME, "onResume()");
    	super.onResume();
    	mGLSurfaceView.onResume();
    }
}