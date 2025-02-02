/**
 * @author Levi Armstrong <levi.armstrong@gmail.com>
 *
 * @copyright Copyright (C) 2022 Levi Armstrong <levi.armstrong@gmail.com>
 *
 * @par License
 * GNU Lesser General Public License Version 3, 29 June 2007
 * @par
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 * @par
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * @par
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef TESSERACT_QT_ENVIRONMENT_ENVIRONMENT_COMMANDS_WIDGET_H
#define TESSERACT_QT_ENVIRONMENT_ENVIRONMENT_COMMANDS_WIDGET_H

#include <memory>
#include <QWidget>

class QItemSelectionModel;

namespace tesseract_gui
{
class ComponentInfo;
class EnvironmentCommandsModel;
class EnvironmentCommandsWidget : public QWidget
{
  Q_OBJECT

public:
  explicit EnvironmentCommandsWidget(QWidget* parent = nullptr);
  explicit EnvironmentCommandsWidget(ComponentInfo component_info, QWidget* parent = nullptr);
  ~EnvironmentCommandsWidget();

  void setComponentInfo(ComponentInfo component_info);
  const ComponentInfo& getComponentInfo() const;

  void setModel(std::shared_ptr<EnvironmentCommandsModel> model);
  std::shared_ptr<EnvironmentCommandsModel> getModel();
  std::shared_ptr<const EnvironmentCommandsModel> getModel() const;

  QItemSelectionModel& getSelectionModel();
  const QItemSelectionModel& getSelectionModel() const;

private:
  struct Implementation;
  std::unique_ptr<Implementation> data_;

  void ctor(ComponentInfo component_info);
};

}  // namespace tesseract_gui
#endif  // TESSERACT_QT_ENVIRONMENT_ENVIRONMENT_COMMANDS_WIDGET_H
