
#ifndef DIALOG_DUPLICATE_TAGS_H_
#define DIALOG_DUPLICATE_TAGS_H_

#include "Dialog.h"
#include "ui_DialogDuplicateTags.h"

class DocumentWidget;
class TextArea;

class DialogDuplicateTags final : public Dialog {
	Q_OBJECT
public:
	DialogDuplicateTags(DocumentWidget *document, TextArea *area, Qt::WindowFlags f = Qt::WindowFlags());
	~DialogDuplicateTags() noexcept override = default;

public:
	void setTag(const QString &tag);
	void addListItem(const QString &text, int id);

private Q_SLOTS:
	void on_buttonBox_accepted();
	void on_buttonBox_clicked(QAbstractButton *button);

private:
	bool applySelection();

private:
	Ui::DialogDuplicateTags ui;
	DocumentWidget *document_;
	TextArea *area_;
};

#endif
