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
#ifndef TESSERACT_QT_COMMON_TOOL_PATH_RENDER_MANAGER_H
#define TESSERACT_QT_COMMON_TOOL_PATH_RENDER_MANAGER_H

#include <memory>
#include <QObject>

namespace tesseract_gui::events
{
class ComponentEvent;
}

namespace tesseract_gui
{
struct ComponentInfo;

class ToolPathRenderManager : public QObject
{
public:
  using Ptr = std::shared_ptr<ToolPathRenderManager>;
  using ConstPtr = std::shared_ptr<const ToolPathRenderManager>;
  using UPtr = std::unique_ptr<ToolPathRenderManager>;
  using ConstUPtr = std::unique_ptr<const ToolPathRenderManager>;

  ToolPathRenderManager(ComponentInfo component_info);
  ~ToolPathRenderManager();

protected:
  std::unique_ptr<ComponentInfo> component_info_;
  std::vector<std::unique_ptr<events::ComponentEvent>> events_;

  // Documentation inherited
  bool eventFilter(QObject* obj, QEvent* event) override;

  virtual void render() = 0;
};
}  // namespace tesseract_gui

#endif  // TESSERACT_QT_COMMON_TOOL_PATH_RENDER_MANAGER_H
