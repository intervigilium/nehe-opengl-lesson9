/* 	TutorialView.java
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

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;

public class TutorialView extends GLSurfaceView {

	private static final String CLASS_NAME = "TutorialView";
	
	private TutorialRenderer mRenderer;
	
	public TutorialView(Context context) {
		super(context);
		mRenderer = new TutorialRenderer(context);
		setRenderer(mRenderer);
	}
	
	@Override
    public void onPause() {
    	Log.i(CLASS_NAME, "onPause()");
    	super.onPause();
    	nativePause();
    }
    
    @Override
    public void onResume() {
    	Log.i(CLASS_NAME, "onResume()");
    	super.onResume();
    	nativeResume();
    }
    
    public void onDestroy() {
    	nativeCleanup();
    }

	@Override
    public boolean onTrackballEvent(MotionEvent event) {
    	return false;
    }
    
    @Override
    public boolean onTouchEvent(MotionEvent event) {
    	return false;
    }
    
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
    	nativeHandleKeyEvent(keyCode);
    	return true;
    }
    
    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event) {
    	nativeHandleKeyEvent(keyCode);
    	return true;
    }
    
    private static native void nativePause();
    private static native void nativeResume();
    private static native void nativeCleanup();
    private static native void nativeHandleKeyEvent(int keyCode);
}
