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
#ifndef TESSERACT_QT_TOOL_PATH_TOOL_PATH_MODEL_H
#define TESSERACT_QT_TOOL_PATH_TOOL_PATH_MODEL_H

#include <tesseract_common/macros.h>
TESSERACT_COMMON_IGNORE_WARNINGS_PUSH
#ifndef Q_MOC_RUN
#include <tesseract_qt/common/tool_path_standard_item.h>
#include <QStandardItemModel>
#endif
TESSERACT_COMMON_IGNORE_WARNINGS_POP

namespace tesseract_gui
{
class ToolPathModel : public QStandardItemModel
{
  Q_OBJECT

public:
  explicit ToolPathModel(std::string scene_name = "", QObject* parent = nullptr);

  /**
   * @brief Add tool path
   * @param trajectory_set The tool path associated with the key
   */
  void addToolPath(const ToolPath& tool_path);

  /**
   * @brief Remove the tool path
   * @param key The uuid associated with the tool path to be removed
   */
  void removeToolPath(const boost::uuids::uuid& uuid);

  /**
   * @brief Check a tool path with the provided key exists
   * @param uuid The uuid associated with the tool path to find
   * @return True if a tool path exists under the provided key, otherwise false
   */
  bool hasToolPath(const boost::uuids::uuid& uuid);

  Eigen::Isometry3d getTransform(const QModelIndex& row) const;
  ToolPathSegment getToolPathSegment(const QModelIndex& row) const;
  ToolPath getToolPath(const QModelIndex& row) const;

  bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

  void clear();

private:
  std::string scene_name_;
  std::map<boost::uuids::uuid, QStandardItem*> tool_paths_;

  // Documentation inherited
  bool eventFilter(QObject* obj, QEvent* event) override;
};

}  // namespace tesseract_gui

#endif  // TESSERACT_QT_TOOL_PATH_TOOL_PATH_MODEL_H
