/*==============================================================================

    Mosaic: Live Visual Patching Creative-Coding Platform

    Copyright (c) 2018 Emanuele Mazza aka n3m3da <emanuelemazza@d3cod3.org>

    Mosaic is distributed under the MIT License. This gives everyone the
    freedoms to use Mosaic in any context: commercial or non-commercial,
    public or private, open or closed source.

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.

    See https://github.com/d3cod3/Mosaic for documentation

==============================================================================*/

#include "SplashScreen.h"

//--------------------------------------------------------------
void SplashScreen::setup(){
    ofSetEscapeQuitsApp(false);
    ofSetVerticalSync(true);

    if(ofGetScreenWidth() >= 2560 && ofGetScreenHeight() >= 1600){ // RETINA SCREEN
        ofSetWindowShape(854,560);
        ofSetWindowPosition(ofGetScreenWidth()/2 - 427,ofGetScreenHeight()/2 - 280);
        font.load("fonts/IBMPlexSans-Text.otf",160);
    }else{
        font.load("fonts/IBMPlexSans-Text.otf",80);
    }

    startTime = ofGetElapsedTimeMillis();

    // load background
    background.load("videos/splash_background.mov");
    background.setLoopState(OF_LOOP_NORMAL);
    background.play();

    ofGetCurrentWindow()->makeCurrent();
}

//--------------------------------------------------------------
void SplashScreen::update(){
    background.update();

    if(ofGetElapsedTimeMillis()-startTime > 6000){
        ofGetCurrentWindow()->setWindowShouldClose();
    }
}

//--------------------------------------------------------------
void SplashScreen::draw(){
    ofBackground(0);
    ofEnableAlphaBlending();

    ofSetColor(255);
    // draw background
    background.draw(0,0,ofGetCurrentWindow()->getWidth(),ofGetCurrentWindow()->getHeight());

    ofSetColor(255,6);
    if(ofGetScreenWidth() >= 2560 && ofGetScreenHeight() >= 1600){ // RETINA SCREEN
        font.drawString(VERSION_GRAPHIC,452,182);
    }else{
        font.drawString(VERSION_GRAPHIC,226,91);
    }
}

//--------------------------------------------------------------
void SplashScreen::mousePressed(int x, int y, int button){
    ofGetCurrentWindow()->setWindowShouldClose();
}
