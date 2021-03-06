//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2016 by EMGU Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#pragma once
#ifndef EMGU_HIGHGUI_C_H
#define EMGU_HIGHGUI_C_H

#include "opencv2/videoio/videoio_c.h"
#include "opencv2/videoio/videoio.hpp"

#if WINAPI_FAMILY
//using namespace System;
//using namespace System::Runtime::InteropServices;
#include "opencv2/videoio/cap_winrt.hpp"
//#include <msclr/gcroot.h>
#endif

struct ColorPoint
{
   CvPoint3D32f position;
   unsigned char blue;
   unsigned char green;
   unsigned char red;
};

CVAPI(void) OpenniGetColorPoints(
                                 CvCapture* capture, // must be an openni capture
                                 std::vector<ColorPoint>* points, // sequence of ColorPoint
                                 IplImage* mask // CV_8UC1
                                 );

CVAPI(cv::VideoCapture*) cveVideoCaptureCreateFromDevice(int device);
CVAPI(cv::VideoCapture*) cveVideoCaptureCreateFromFile(cv::String* fileName);
CVAPI(void) cveVideoCaptureRelease(cv::VideoCapture** capture);
CVAPI(bool) cveVideoCaptureSet(cv::VideoCapture* capture, int propId, double value);
CVAPI(double) cveVideoCaptureGet(cv::VideoCapture* capture, int propId);
CVAPI(bool) cveVideoCaptureGrab(cv::VideoCapture* capture);
CVAPI(bool) cveVideoCaptureRetrieve(cv::VideoCapture* capture, cv::_OutputArray* image, int flag);
CVAPI(bool) cveVideoCaptureRead(cv::VideoCapture* capture, cv::_OutputArray* image);

CVAPI(void) cveVideoCaptureReadToMat(cv::VideoCapture* capture, cv::Mat* mat);

#if WINAPI_FAMILY
CVAPI(void) cveWinrtSetFrameContainer(::Windows::UI::Xaml::Controls::Image^ image);
typedef void (CV_CDECL *CvWinrtMessageLoopCallback)();
CVAPI(void) cveWinrtStartMessageLoop(CvWinrtMessageLoopCallback callback);
CVAPI(void) cveWinrtImshow();
CVAPI(void) cveWinrtOnVisibilityChanged(bool visible);
#endif

CVAPI(cv::VideoWriter*) cveVideoWriterCreate(cv::String* filename, int fourcc, double fps, CvSize* frameSize, bool isColor);
CVAPI(void) cveVideoWriterRelease(cv::VideoWriter** writer);
CVAPI(void) cveVideoWriterWrite(cv::VideoWriter* writer, cv::Mat* image);
CVAPI(int) cveVideoWriterFourcc(char c1, char c2, char c3, char c4);

#endif