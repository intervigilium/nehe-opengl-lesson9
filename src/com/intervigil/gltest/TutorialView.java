package com.intervigil.gltest;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.KeyEvent;
import android.view.MotionEvent;

public class TutorialView extends GLSurfaceView {

	private TutorialRenderer mRenderer;
	
	public TutorialView(Context context) {
		super(context);
		mRenderer = new TutorialRenderer();
		setRenderer(mRenderer);
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
    
    private static native void nativeHandleKeyEvent(int keyCode);
}
