/***********************************************************************
    filename:   SILLYImageLoader.h
    created:    10 Jun 2006
    author:     Olivier Delannoy

    purpose:    Abstract class for all image loader 
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2006 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#ifndef _SILLYImageLoader_h_ 
#define _SILLYImageLoader_h_
#include "SILLYBase.h"
// Start of section namespace SILLY 
namespace SILLY
{
class DataSource; 		// Forward declaration
class ImageContext;		// Forward declaration
 
/*! 
  \brief
    This is an abstract class that define the interface of all image loader 
*/
class SILLY_EXPORT ImageLoader
{
public:
    /*!
      \brief 
      Destructor 
    */
    virtual ~ImageLoader();

    /*! 
      \brief 
      Parse the header of the image and fill the header struct 
      
      \param header the Image header 

      \param data the input of the image data 

      \return Context for the rest of the parsing or 0 if an error occured 
    */
    virtual ImageContext* loadHeader(size_t& width, size_t& height, PixelFormat& formatSource, DataSource* data) = 0;


    /*!
      \brief 
      Parse the pixels data of the image and fill the header struct 
      
      \param data the input of the image data

      \param context the data associated to the image parsing 
      
      \return true on success false on error 
    */
    virtual bool loadImageData(PixelFormat resultFormat, DataSource* data, ImageContext* context) = 0;
    
    /*! 
      \brief 
      Destroy the image context 
      
      \param context a pointer to the context 
    */
    void destroyContext(ImageContext* context);
};
  
} // End of section namespace SILLY 

// Inclue inline function when needed 
#ifdef SILLY_OPT_INLINE
#include "SILLYImageLoader.icpp"
#endif 

#endif // end of guard _SILLYImageLoader_h_
