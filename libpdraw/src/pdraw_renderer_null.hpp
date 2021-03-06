/**
 * @file pdraw_renderer_null.hpp
 * @brief Parrot Drones Awesome Video Viewer Library - null renderer
 * @date 05/11/2016
 * @author aurelien.barre@akaaba.net
 *
 * Copyright (c) 2016 Aurelien Barre <aurelien.barre@akaaba.net>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 * 
 *   * Neither the name of the copyright holder nor the names of the
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _PDRAW_RENDERER_NULL_HPP_
#define _PDRAW_RENDERER_NULL_HPP_

#include <pthread.h>

#include "pdraw_renderer.hpp"


namespace Pdraw
{


class NullRenderer : public Renderer
{
public:

    NullRenderer(Session *session);

    ~NullRenderer();

    int addAvcDecoder(AvcDecoder *decoder);

    int removeAvcDecoder(AvcDecoder *decoder);

    int setRendererParams
            (int windowWidth, int windowHeight,
             int renderX, int renderY,
             int renderWidth, int renderHeight,
             void *uiHandler);

    int render(int timeout);

    Session *getSession() { return mSession; };

private:

    static void* runRendererThread(void *ptr);

    AvcDecoder *mDecoder;
    BufferQueue *mDecoderOutputBufferQueue;
    pthread_t mRendererThread;
    bool mRendererThreadLaunched;
    bool mThreadShouldStop;
};

}

#endif /* !_PDRAW_RENDERER_NULL_HPP_ */
