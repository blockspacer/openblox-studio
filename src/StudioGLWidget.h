/*
 * Copyright (C) 2017 John M. Harris, Jr. <johnmh@openblox.org>
 *
 * This file is part of OpenBlox Studio.
 *
 * OpenBlox Studio is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenBlox Studio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 * along with OpenBlox Studio.	 If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef OB_STUDIO_STUDIOGLWIDGET_H_
#define OB_STUDIO_STUDIOGLWIDGET_H_

#include "StudioTabWidget.h"

#include "StudioWindow.h"

namespace OB{
	namespace Studio{
		class StudioGLWidget: public StudioTabWidget{
		  public:
			StudioGLWidget(OBEngine* eng);
			virtual ~StudioGLWidget();

			QSize minimumSizeHint() const;
			QSize sizeHint() const;

			void init();

			virtual void paintEvent(QPaintEvent* evt);
			virtual void resizeEvent(QResizeEvent* evt);
			virtual void timerEvent(QTimerEvent* evt);

			void setLogHistory(QString hist);
			QString getLogHistory();

			void populateTree(InstanceTree* explorer);

			void saveAct();
			void saveAsAct();

			QString fileOpened;

			std::vector<shared_ptr<Instance::Instance>> selectedInstances;

			// Explorer handling
			void sendOutput(QString msg, QColor col);
			void sendOutput(QString msg);

			void handle_log_event(std::vector<shared_ptr<OB::Type::VarWrapper>> evec, void* ud);
			void instance_changed_evt(std::vector<shared_ptr<Type::VarWrapper>> evec, void* ud);
			void instance_child_added_evt(std::vector<shared_ptr<Type::VarWrapper>> evec, void* ud);
			void instance_child_removed_evt(std::vector<shared_ptr<Type::VarWrapper>> evec, void* ud);
			void addChildOfInstance(QTreeWidgetItem* parentItem, shared_ptr<Instance::Instance> kid);
			void addChildrenOfInstance(QTreeWidgetItem* parentItem, shared_ptr<Instance::Instance> inst);
			void dm_changed_evt(std::vector<shared_ptr<Type::VarWrapper>> evec, void* ud);
			void addDM(QTreeWidgetItem* parentItem, shared_ptr<Instance::Instance> inst, StudioWindow* sw);
			
		  protected:
			void paintGL();
			void resizeGL(int width, int height);
			void mousePressEvent(QMouseEvent* event);
			void mouseMoveEvent(QMouseEvent* event);

			QMap<shared_ptr<Instance::Instance>, InstanceTreeItem*> treeItemMap;
			
		  private:
			QString logHist;
		};
	}
}

#endif
