/*
 * ComputerMonitoringWidget.h - provides a view with computer monitor thumbnails
 *
 * Copyright (c) 2017-2020 Tobias Junghans <tobydox@veyon.io>
 *
 * This file is part of Veyon - https://veyon.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#pragma once

#include "ComputerMonitoringView.h"
#include "FlexibleListView.h"

#include <QWidget>

class FlexibleListView;

class ComputerMonitoringWidget : public FlexibleListView, public ComputerMonitoringView
{
	Q_OBJECT
public:
	explicit ComputerMonitoringWidget( QWidget *parent = nullptr );
	~ComputerMonitoringWidget() override = default;

	ComputerControlInterfaceList selectedComputerControlInterfaces() const override;

	void autoAdjustComputerScreenSize();

	void setUseCustomComputerPositions( bool enabled ) override;
	void alignComputers() override;

	void showContextMenu( QPoint globalPos );

private:
	void setColors( const QColor& backgroundColor, const QColor& textColor ) override;
	QJsonArray saveComputerPositions() override;
	bool useCustomComputerPositions() override;
	void loadComputerPositions( const QJsonArray& positions ) override;
	void setIconSize( const QSize& size ) override;

	void populateFeatureMenu( const FeatureUidList& activeFeatures );
	void addFeatureToMenu( const Feature& feature, const QString& label );
	void addSubFeaturesToMenu( const Feature& parentFeature, const FeatureList& subFeatures, const QString& label );

	void runDoubleClickFeature( const QModelIndex& index );

	void showEvent( QShowEvent* event ) override;
	void wheelEvent( QWheelEvent* event ) override;

	QMenu* m_featureMenu{};

Q_SIGNALS:
	void computerScreenSizeAdjusted( int size );

};
