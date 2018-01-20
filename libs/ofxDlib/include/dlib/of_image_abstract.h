////
//// Copyright (c) 2018 Christopher Baker <https://christopherbaker.net>
////
//// SPDX-License-Identifier:	MIT
////


//#pragma once


//#include <dlib/algs.h>
//#include <dlib/pixel.h>
//#include <dlib/matrix.h>


///// \sa http://dlib.net/dlib/opencv/of_image_abstract.h.html
//namespace dlib
//{

//template <
//    typename pixel_type,
//    typename T
//    >
//class of_image
//{
//    /*!
//        REQUIREMENTS ON pixel_type
//            pixel_type just needs to be something that matches the pixel memory
//            layout of whatever OpenCV image you are going to use with this object.
//            For example, you might use unsigned char or bgr_pixel depending
//            on what you needed.

//        WHAT THIS OBJECT REPRESENTS
//            This object is meant to be used as a simple wrapper around the OpenCV
//            IplImage struct or Mat object.  Using this class template you can turn
//            an OpenCV image into something that looks like a normal dlib style
//            image object.

//            So you should be able to use of_image objects with many of the image
//            processing functions in dlib as well as the GUI tools for displaying
//            images on the screen.

//            Note that this object does NOT take ownership of the image data you
//            give to it.  This means it is up to you to make sure the OpenCV image
//            is properly freed at some point.  This also means that an instance of
//            this object can only be used as long as the OpenCV image it references
//            remains valid, since a of_image just points to the OpenCV image's
//            memory directly.
//    !*/

//public:
//    typedef pixel_type type;
//    //typedef default_memory_manager mem_manager_type;

//    of_image (
//        const ofPixels_<T>* img
//    );
//    /*!
//        requires
//            - img->dataOrder == 0
//              (i.e. Only interleaved color channels are supported with of_image)
//            - (img->depth&0xFF)/8*img->nChannels == sizeof(pixel_type)
//              (i.e. The size of the pixel_type needs to match the size of the pixels
//              inside the OpenCV image)
//        ensures
//            - #nr() == img->height
//              #nc() == img->width
//            - using the operator[] on this object you will be able to access the pixels
//              inside this OpenCV image.
//    !*/

//    of_image (
//        const ofPixels_<T> img
//    );
//    /*!
//        requires
//            - img.dataOrder == 0
//              (i.e. Only interleaved color channels are supported with of_image)
//            - (img.depth&0xFF)/8*img.nChannels == sizeof(pixel_type)
//              (i.e. The size of the pixel_type needs to match the size of the pixels
//              inside the OpenCV image)
//        ensures
//            - #nr() == img.height
//              #nc() == img.width
//            - using the operator[] on this object you will be able to access the pixels
//              inside this OpenCV image.
//    !*/

//    of_image(
//    );
//    /*!
//        ensures
//            - #nr() == 0
//            - #nc() == 0
//    !*/

//    ~of_image (
//    );
//    /*!
//        ensures
//            - This function does nothing.  e.g. It doesn't delete the OpenCV
//              image used by this of_image object
//    !*/

//    long nr(
//    ) const;
//    /*!
//        ensures
//            - returns the number of rows in this image
//    !*/

//    long nc(
//    ) const;
//    /*!
//        ensures
//            - returns the number of columns in this image
//    !*/

//    unsigned long size (
//    ) const;
//    /*!
//        ensures
//            - returns nr()*nc()
//              (i.e. returns the number of pixels in this image)
//    !*/

//    inline pixel_type* operator[] (
//        const long row
//    );
//    /*!
//        requires
//            - 0 <= row < nr()
//        ensures
//            - returns a pointer to the first pixel in the given row
//              of this image
//    !*/

//    inline const pixel_type* operator[] (
//        const long row
//    ) const;
//    /*!
//        requires
//            - 0 <= row < nr()
//        ensures
//            - returns a pointer to the first pixel in the given row
//              of this image
//    !*/

//    inline const pixel_type& operator()(
//        const long row, const long column
//    ) const;
//    /*!
//        requires
//            - 0 <= row < nr()
//            - 0 <= column < nc()
//        ensures
//            - returns a const reference to the pixel at coordinates (row, column)
//              of this image
//    !*/

//    inline pixel_type& operator()(
//        const long row, const long column
//    );
//    /*!
//        requires
//            - 0 <= row < nr()
//            - 0 <= column < nc()
//        ensures
//            - returns a reference to the pixel at coordinates (row, column)
//              of this image
//    !*/

//    of_image& operator= (
//        const of_image& item
//    );
//    /*!
//        ensures
//            - #*this is an identical copy of item
//            - returns #*this
//    !*/

//    of_image& operator=(
//        const ofPixels_<T>* img
//    );
//    /*!
//        requires
//            - img->dataOrder == 0
//              (i.e. Only interleaved color channels are supported with of_image)
//            - (img->depth&0xFF)/8*img->nChannels == sizeof(pixel_type)
//              (i.e. The size of the pixel_type needs to match the size of the pixels
//              inside the OpenCV image)
//        ensures
//            - #nr() == img->height
//              #nc() == img->width
//            - using the operator[] on this object you will be able to access the pixels
//              inside this OpenCV image.
//            - returns #*this
//    !*/

//    of_image& operator=(
//        const ofPixels_<T> img
//    );
//    /*!
//        requires
//            - img->dataOrder == 0
//              (i.e. Only interleaved color channels are supported with of_image)
//            - (img->depth&0xFF)/8*img->nChannels == sizeof(pixel_type)
//              (i.e. The size of the pixel_type needs to match the size of the pixels
//              inside the OpenCV image)
//        ensures
//            - #nr() == img->height
//              #nc() == img->width
//            - using the operator[] on this object you will be able to access the pixels
//              inside this OpenCV image.
//            - returns #*this
//    !*/

////    of_image& operator=(
////        const cv::Mat img
////    );
////    /*!
////        requires
////            - img.depth() == cv::DataType<pixel_traits<pixel_type>::basic_pixel_type>::depth
////              (i.e. The pixel_type template argument needs to match the type of pixel
////              used inside the OpenCV image)
////            - img.channels() == pixel_traits<pixel_type>::num
////              (i.e. the number of channels in the pixel_type needs to match the number of
////              channels in the OpenCV image)
////        ensures
////            - #nr() == img.rows
////            - #nc() == img.cols
////            - using the operator[] on this object you will be able to access the pixels
////              inside this OpenCV image.
////            - returns #*this
////    !*/

//    long width_step (
//    ) const;
//    /*!
//        ensures
//            - returns the size of one row of the image, in bytes.
//              More precisely, return a number N such that:
//              (char*)&item[0][0] + N == (char*)&item[1][0].
//    !*/
//};

//// ----------------------------------------------------------------------------------------

//template <
//    typename pixel_type,
//        typename T
//    >
//const matrix_exp<pixel_type> mat (
//    const of_image<pixel_type, T>& img
//);
///*!
//    ensures
//        - returns a matrix R such that:
//            - R.nr() == img.nr()
//            - R.nc() == img.nc()
//            - for all valid r and c:
//              R(r, c) == img[r][c]
//!*/


//} // namespace dlib