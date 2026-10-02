// Translated (2026-10) from the JSR-184 (M3G) Java API of Nokia's reference
// implementation, as adapted by J2ME Loader and Deep3D-PC.
// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// Made available under the terms of the Eclipse Public License v1.0
// (http://www.eclipse.org/legal/epl-v10.html); the changes likewise.
#include "m3g.h"


void javax::microedition::m3g::M3gRunnable::__clinit() {
}

void javax::microedition::m3g::M3gRunnable::__init() {
    this->e = jrt::Ref<java::lang::Throwable>(nullptr);
}

void javax::microedition::m3g::M3gRunnable::run() {
    {
        try {
            this->doRun();
        } catch (const jrt::Thrown& __ex1) {
            if (jrt::isInstance<java::lang::Throwable>(__ex1.t)) {
                jrt::Ref<java::lang::Throwable> t = jrt::cast<java::lang::Throwable>(__ex1.t);
                this->e = t;
            } else {
                throw;
            }
        }
    }
}

void javax::microedition::m3g::M3gRunnable::checkAndThrow() {
    if (this->e == nullptr) {
        return;
    }
    if (jrt::isInstance<java::lang::RuntimeException>(this->e)) {
        jrt::throwJava(jrt::cast<java::lang::RuntimeException>(this->e));
    } else if (jrt::isInstance<java::lang::Error>(this->e)) {
        jrt::throwJava(jrt::cast<java::lang::Error>(this->e));
    }
}

