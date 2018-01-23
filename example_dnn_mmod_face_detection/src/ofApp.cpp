//
// Copyright (c) 2017 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


void ofApp::setup()
{
    // Instantiate the network.
    net_type net;

    // Load the network data.
    dlib::deserialize(ofToDataPath("mmod_human_face_detector.dat", true)) >> net;

    // Load the image.
    ofPixels pix;
    ofLoadImage(pix, "crowd.jpg");

    // Note that you can process a bunch of images in a std::vector at once and
    // it runs much faster, since this will form mini-batches of images and
    // therefore get better parallelism out of your GPU hardware.  However, all
    // the images must be the same size.  To avoid this requirement on images
    // being the same size we process them individually in this example.
    auto dets = net(dlib::mat(pix));

    // ~16 seconds on MacBook Pro (15-inch, Mid 2012), no CUDA support.
    // ~1.2 seconds on i7 7700 + Nvidia 1080, CUDA support + MKL libs.

    std::cout << "Found " << dets.size() << " faces." << std::endl;

    image.setFromPixels(pix);
}


void ofApp::draw()
{
    ofBackground(0);
    ofNoFill();
    ofSetColor(ofColor::white);

    image.draw(0, 0);

    for (auto& r: dets)
    {
        std::stringstream ss;
        ss << "Confidence: " << r.detection_confidence << std::endl;
        ss << "Ignore: " << r.ignore;

        ofRectangle rect = ofxDlib::toOf(r);

        ofDrawRectangle(rect);
        ofPopMatrix();
        ofDrawBitmapString(ss.str(), rect.getCenter());
    }
}
