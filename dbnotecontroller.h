#pragma once
#include "notecontroller.h"
#include <QSqlDatabase>


class DBNoteController
    : public INoteController
{
    Q_OBJECT
public:
    QML_ELEMENT

    DBNoteController();

    QVector<NoteId> getNotes() const override;

    NoteId createNote() override;
    void removeNote(NoteId id) override;
    QString getNoteName(NoteId id) const override;
    void setNoteName(NoteId id, const QString& name) override;
    QString getNoteText(NoteId id) const override;
    void setNoteText(NoteId id, const QString& text) override;
    QStringList getNoteTags(NoteId id) const override;
    void setNoteTags(NoteId id, const QStringList& tags) override;
    int64_t getNoteCreationTimestamp(NoteId id) const override;
    int64_t getNoteUpdateTimestamp(NoteId id) const override;

    bool nameExists(const QString& title) const;

private:
    static void prepareQuery(QSqlQuery& query, const QString& s);
    static void execQuery(QSqlQuery& query);

    QVariant queryField(NoteId id, const QString& name) const;
    void queryField(NoteId id, const QString& name, const QVariant& value);

    void onDbNotification(const QString& name);

private:
    QSqlDatabase _db;
};
