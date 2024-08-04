// This is the source code of AyuGram for Desktop.
//
// We do not and cannot prevent the use of our code,
// but be respectful and credit the original author.
//
// Copyright @Radolyn, 2024
#pragma once

#include <QtNetwork/QNetworkReply>
#include <QtXml/QDomDocument>

class AyuCustomLangPack : public QObject
{
	Q_OBJECT
	Q_DISABLE_COPY(AyuCustomLangPack)

public:
	static AyuCustomLangPack *currentInstance();
	static void initInstance();
	static AyuCustomLangPack *instance;

	void fetchCustomLangPack(const QString &langPackId, const QString &langPackBaseId);
	void loadDefaultLangFile();
	void parseLangFile(QJsonDocument str);

public Q_SLOTS:
	void fetchFinished();
	void fetchError(QNetworkReply::NetworkError e);

private:
	AyuCustomLangPack();
	~AyuCustomLangPack() override = default;

	QNetworkAccessManager networkManager;
	QNetworkReply *_chkReply = nullptr;
	bool needFallback = false;
};
