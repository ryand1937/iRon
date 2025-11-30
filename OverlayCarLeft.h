/*
MIT License

Copyright (c) 2021-2022 L. E. Spalt

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include "Overlay.h"
#include "Config.h"
#include "OverlayDebug.h"



class OverlayCarLeft : public Overlay
{
    public:

        OverlayCarLeft()
            : Overlay("OverlayCarLeft")
        {}

    protected:

        virtual float2 getDefaultSize()
        {
            return float2(80,80);
        }
        virtual bool hasCustomBgColor()
        {
            return true;
        }
        virtual void onUpdate()
        {
            
            const float w = static_cast<float>(m_width);
            const float h = static_cast<float>(m_height);

            int val = ir_CarLeftRight.getInt();
            m_isLeft = (val == 2 || val == 4);

            m_renderTarget->BeginDraw();
                     
            D2D1_ROUNDED_RECT Box = {};
        
            Box.rect = {10, 10,(w-10),(h-10)};
            Box.radiusX = 3;
            Box.radiusY = 3;

            // Set brush to opaque Yellow
            m_brush->SetColor(D2D1::ColorF(1.0f, 1.0f, 0.0f, m_isLeft));

            // Draw the Indiator
            m_renderTarget->FillRoundedRectangle(&Box, m_brush.Get());

            m_renderTarget->EndDraw();
        }


    protected:
        bool m_isLeft;
       
};
