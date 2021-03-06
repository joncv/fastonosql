/*  Copyright (C) 2014-2018 FastoGT. All right reserved.

    This file is part of FastoNoSQL.

    FastoNoSQL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoNoSQL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoNoSQL.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <QDialog>

class QLineEdit;
class QPushButton;
class QLabel;

namespace common {
namespace qt {
namespace gui {
class IconLabel;
}
}  // namespace qt
}  // namespace common

namespace fastonosql {
namespace gui {

class PasswordDialog : public QDialog {
  Q_OBJECT
 public:
  explicit PasswordDialog(QWidget* parent = Q_NULLPTR);
  explicit PasswordDialog(const QString& description, QWidget* parent = Q_NULLPTR);

  QString GetLogin() const;
  void SetLogin(const QString& login);

  QString GetPassword() const;
  void SetPassword(const QString& password);

  void SetLoginEnabled(bool en);

  void SetDescription(const QString& description);
  QString GetDescription() const;

  bool IsVisibleDescription() const;
  bool IsVisibleStatus() const;

  void SetFocusInPassword();
  void SetFocusInLogin();

 public Q_SLOTS:
  virtual void accept() override;

  void SetVisibleDescription(bool visible);
  void SetVisibleStatus(bool visible);
  void SetStatusIcon(const QIcon& icon, const QSize& icon_size);
  void SetStatus(const QString& status);

 private Q_SLOTS:
  void togglePasswordEchoMode();

 protected:
  virtual void changeEvent(QEvent* ev) override;

 private:
  void retranslateUi();
  void syncShowButton();

 private:
  QLabel* description_;

  QLabel* login_label_;
  QLineEdit* login_box_;

  QLabel* password_label_;
  QLineEdit* password_box_;
  QPushButton* password_echo_mode_button_;

  common::qt::gui::IconLabel* status_label_;
};

}  // namespace gui
}  // namespace fastonosql
