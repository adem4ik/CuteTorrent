/****************************************************************************
 **
 ** Copyright (C) 2013 Ivan Vizir <define-true-false@yandex.com>
 ** Copyright (C) 2015 The Qt Company Ltd.
 ** Contact: http://www.qt.io/licensing/
 **
 ** This file is part of the QtWinExtras module of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:LGPL21$
 ** Commercial License Usage
 ** Licensees holding valid commercial Qt licenses may use this file in
 ** accordance with the commercial license agreement provided with the
 ** Software or, alternatively, in accordance with the terms contained in
 ** a written agreement between you and The Qt Company. For licensing terms
 ** and conditions see http://www.qt.io/terms-conditions. For further
 ** information use the contact form at http://www.qt.io/contact-us.
 **
 ** GNU Lesser General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU Lesser
 ** General Public License version 2.1 or version 3 as published by the Free
 ** Software Foundation and appearing in the file LICENSE.LGPLv21 and
 ** LICENSE.LGPLv3 included in the packaging of this file. Please review the
 ** following information to ensure the GNU Lesser General Public License
 ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
 ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 **
 ** As a special exception, The Qt Company gives you certain additional
 ** rights. These rights are described in The Qt Company LGPL Exception
 ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
 **
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

#include "qwinevent.h"

const int QWinEvent::ColorizationChange = QEvent::registerEventType();
const int QWinEvent::CompositionChange = QEvent::registerEventType();
const int QWinEvent::TaskbarButtonCreated = QEvent::registerEventType();
const int QWinEvent::TaskbarButtonClicked = QEvent::registerEventType();
const int QWinEvent::RequestThumbnailBitmap = QEvent::registerEventType();
const int QWinEvent::RequestLivePreviewBitmap = QEvent::registerEventType();
const int QWinEvent::ThemeChange = QEvent::registerEventType();

QWinEvent::QWinEvent(int type) : QEvent(static_cast<QEvent::Type>(type))
{
}

QWinEvent::~QWinEvent()
{
}

QWinColorizationChangeEvent::QWinColorizationChangeEvent(QRgb color, bool opaque)
    : QWinEvent(ColorizationChange), rgb(color), opaque(opaque)
{
}

QWinColorizationChangeEvent::~QWinColorizationChangeEvent()
{
}

QWinCompositionChangeEvent::QWinCompositionChangeEvent(bool enabled)
    : QWinEvent(CompositionChange), enabled(enabled)
{
}

QWinCompositionChangeEvent::~QWinCompositionChangeEvent()
{
}

QWinTaskBarButtonClicked::QWinTaskBarButtonClicked(unsigned short buttonId): QWinEvent(TaskbarButtonClicked)
{
	this->buttonId = buttonId;
}

unsigned short QWinTaskBarButtonClicked::getClickedButtonId() const
{
	return this->buttonId;
}

QWinRequestThumbnailBitmap::QWinRequestThumbnailBitmap(QSize maxSize, HWND hwnd): QWinEvent(RequestThumbnailBitmap), m_maxSize(maxSize), m_hwnd(hwnd)
{
}

QSize QWinRequestThumbnailBitmap::maxSize() const
{
	return m_maxSize;
}

QWinRequestLivePreviewBitmap::QWinRequestLivePreviewBitmap(HWND hwnd) : QWinEvent(RequestLivePreviewBitmap)
{
	m_hwnd = hwnd;
}

HWND QWinRequestLivePreviewBitmap::hwnd() const
{
	return m_hwnd;
}

HWND QWinRequestThumbnailBitmap::hwnd() const
{
	return m_hwnd;
}
