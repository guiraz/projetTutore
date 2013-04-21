#include "db.h"

Db::Db()
{
    QString path(qApp->applicationDirPath());
    path.append(QDir::separator()).append("db").append(QDir::separator()).append("dislekclik.sqlite");
    path = QDir::toNativeSeparators(path);

    QString pathDir(qApp->applicationDirPath());
    pathDir.append(QDir::separator()).append("db").append(QDir::separator());
    pathDir = QDir::toNativeSeparators(pathDir);

    QString type = QString("QSQLITE");
    _db = new QSqlDatabase(QSqlDatabase::addDatabase(type));

    if(QFile::exists(path)) //if db already exists
    {
        _db->setDatabaseName(path);
        _db->open();
    }
    else
    {
        QDir d;
        d.mkpath(pathDir);
        _db->setDatabaseName(path);
        _db->open();
        createDB();
    }
}

QSqlError Db::lastError()
{
    return _db->lastError();
}

void Db::closeDB()
{
    _db->close();
}

QSqlDatabase * Db::getDBRef()
{
    return _db;
}

void Db::createDB()
{
    QSqlQuery query;
    query.exec("pragma foreign_keys = off;");
    query.exec("begin transaction;");
    query.exec("pragma auto_vacuum=0;");
    query.exec("pragma encoding='UTF-8';");
    query.exec("pragma page_size=32768;");

    query.exec("DROP TABLE IF EXISTS [EXERCICES];");
    query.exec("CREATE TABLE [EXERCICES] ([ID] INTEGER PRIMARY KEY, [NAME] VARCHAR, [DESC] TEXT);");
    query.exec("INSERT INTO [EXERCICES] VALUES(1, 'Conjugaison', 'Choisir la bonne conjugaison');");
    query.exec("INSERT INTO [EXERCICES] VALUES(2, 'L''intru', 'Trouver l''intru parmis les propositions suivantes');");

    query.exec("DROP TABLE IF EXISTS [PROPOSITIONS];");
    query.exec("CREATE TABLE [PROPOSITIONS] ([ID] INTEGER PRIMARY KEY, [EXERCICE_ID] INTEGER REFERENCES [EXERCICES]([ID]), [PROP1] VARCHAR, [PROP2] VARCHAR, [PROP3] VARCHAR, [PROP4] VARCHAR);");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(1, 1, 'Je mangeais', 'Je mangez', 'Je mangé', 'Je manger');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(2, 1, 'Je dors', 'Je dor', 'Je d''or ', 'Je dehors');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(3, 1, 'Je sors', 'Je sort', 'Je sor', 'Je saur');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(4, 1, 'Il ment', 'Il mens', 'Il m''en', 'Il mant');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(5, 1, 'Vous jouez', 'Vous joué', 'Vous jouer', 'Vous jouai');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(6, 1, 'Ils tombent', 'Ils tombe', 'Ils tombeus', 'Ils tonbent');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(7, 1, 'Nous parlons', 'Nous parlont', 'Nous parlong', 'Nous parlon');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(8, 1, 'Tu dis', 'Tu dit', 'Tu di', 'Tu dix');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(9, 1, 'Ils voient', 'Ils voyent', 'Ils voit', 'Ils voie');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(10, 1, 'Ils croient', 'Ils croit', 'Ils croyent', 'Ils croix');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(11, 1, 'Je fais', 'Je fait', 'Je fée', 'Je fé');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(12, 1, 'Nous faisons', 'Nous fésons', 'Nous faisont', 'Nous ferson');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(13, 1, 'Il dort', 'Il dors', 'Il d''or', 'Il dor');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(14, 1, 'J''écris', 'J''écrit', 'J''aicris', 'J''écri');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(15, 1, 'Je cours', 'Je cour', 'Je court', 'Je coure');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(16, 1, 'Il peut', 'Il peu', 'Il pe', 'Il peus');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(17, 1, 'Tu as', 'Tu a', 'Tu at', 'Tu à');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(18, 1, 'Il est', 'Il es', 'Il é', 'Il ais');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(19, 1, 'Ils sont', 'Ils son', 'Ils sons', 'Ils som');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(20, 1, 'Vous chantiez', 'Vous chantier', 'Vous chantié', 'Vous chantiai');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(21, 1, 'J''ai chanté', 'J''ai chanter', 'J''ai chantez', 'J''ai chantai');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(22, 1, 'Tu as vu', 'Tu a vu', 'Tu à vu', 'Tu as vus');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(23, 1, 'Nous avons chanté', 'Nous avon chanté', 'Nous avont chanté', 'Nous avons chantez');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(24, 1, 'Nous sommes sortis', 'Nous some sortis', 'Nous sommes sortit', 'Nous somme sorti');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(25, 1, 'Ils ont joué', 'Ils on joué', 'Ils ons joué', 'Ils ont jouer');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(26, 1, 'J''ai fait', 'J''ai fé', 'J''ai fer', 'J''ai fais');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(27, 1, 'J''ai été', 'J''ai éter', 'J''ai étez', 'J''ai étiez');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(28, 1, 'Il a pu', 'Il at pu', 'Il à pu', 'Il a pus');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(29, 1, 'Vous avez couru', 'Vous avaient couru', 'Vous avez courru', 'Vous avez couruez');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(30, 1, 'Elles ont parlé', 'Elles ont parlée', 'Elles ont parler', 'Elle on parlé');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(31, 1, 'Vous aimerez', 'Vous aimerais', 'Vous aimerez', 'Vous aimeré');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(32, 1, 'Il marchera', 'Il marcheras', 'Il marcherat', 'Il marcherà');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(33, 1, 'Il partira', 'Il partirat', 'Il partiras', 'Il partirà');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(34, 1, 'Je partirai', 'Je partirez', 'Je partiré', 'Je partirer');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(35, 1, 'J''écrivis', 'J''écrivi', 'J''écrivit', 'J''écrivie');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(36, 1, 'J''écrivais', 'J''écriver', 'J''écrivez', 'J''écrivé');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(37, 1, 'J''écouterai', 'J''écouterais', 'J''écouteraie', 'J''écouterez');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(38, 1, 'Nous habiterons', 'Nous habiteron', 'Nous habiteront', 'Nous habiterom');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(39, 1, 'Tu habiteras', 'Tu habitera', 'Tu habiterat', 'Tu habiterae');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(40, 1, 'Vous mordîtes', 'Vous mordîte', 'Vous mordites', 'Vous mordîtte');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(41, 1, 'Nous avons mordu', 'Nous avons mordus', 'Nous avon mordu', 'Nous avons mordus');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(42, 1, 'Ils rêvaient', 'Ils rêvais', 'Ils rêvaien', 'Ils révaient');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(43, 1, 'Je rêve', 'Je rêves', 'Je réve', 'Je réves');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(44, 1, 'Je bois', 'Je bouas', 'Je boua', 'Je boi');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(45, 1, 'Tu as bu', 'Tu as bus', 'Tu as but', 'Tu a bu');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(46, 1, 'Il délivrera', 'Il dailivrerat', 'Il délivreras', 'Il dailivrera');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(47, 1, 'Vous délivrez', 'Vous délivrer', 'Vous délivrais', 'Vous délivré');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(48, 1, 'J''ai permis', 'J''ai permi', 'J''ai permit', 'J''ai permie');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(49, 1, 'Je prends', 'Je prend', 'Je prant', 'Je prands');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(50, 1, 'Ils ont pris', 'Ils ont prit', 'Ils on pris', 'Ils ons pris');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(51, 2, 'Réparer', 'Nettoyer', 'Frotter', 'Astiquer');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(52, 2, 'Adulte', 'Enfant', 'Gamin', 'Bambin');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(53, 2, 'Inutile', 'Illicite', 'Interdit', 'Illégal');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(54, 2, 'Fenêtre', 'Affiche', 'Pancarte', 'Panneau');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(55, 2, 'Table', 'Boîte', 'Carton', 'Paquet');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(56, 2, 'Gomme', 'Stylo', 'Crayon', 'Feutre');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(57, 2, 'Robinet', 'Bouteille', 'Flacon', 'Fiole');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(58, 2, 'Lit', 'Chaise', 'Tabouret', 'Fauteuil');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(59, 2, 'Télévision', 'Lampadaire', 'Ampoule', 'Néon');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(60, 2, 'Batterie', 'Guitare', 'Violon', 'Basse');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(61, 2, 'Retrouver', 'Cacher', 'Dissimuler', 'Camoufler');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(62, 2, 'Souris', 'Crocodile', 'Serpent', 'Lézard');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(63, 2, 'Régis', 'Mario', 'Sonic', 'Pikachu');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(64, 2, 'Mickey', 'Scar', 'Jafar', 'Adès');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(65, 2, 'Acquérir', 'Livrer', 'Apporter', 'Fournir');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(66, 2, 'Inutilisable', 'Vieux', 'Ancien', 'Vétuste');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(67, 2, 'Comique', 'Dément', 'Dingue', 'Fou');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(68, 2, 'Dire', 'Assurer', 'Certifier', 'Affirmer');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(69, 2, 'Joie', 'Peur', 'Trouille', 'Frousse');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(70, 2, 'Rencontrer', 'Débattre', 'Délibérer', 'Discuter');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(71, 2, 'Taper', 'Gronder', 'Disputer', 'Réprimander');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(72, 2, 'Détruire', 'Trancher', 'Couper', 'Hacher');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(73, 2, 'Content', 'Hilarant', 'Comique', 'Marrant');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(74, 2, 'Regarder', 'Copier', 'Imiter', 'Parodier');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(75, 2, 'Murmurer', 'Crier', 'Hurler', 'Aboyer');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(76, 2, 'Ecrire', 'Discuter', 'Converser', 'Parler');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(77, 2, 'Abaisser', 'Monter', 'Elever', 'Soulever');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(78, 2, 'Tongs', 'Chaussures', 'Bottes', 'Baskets');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(79, 2, 'Roman', 'Magazine', 'Journal', 'Revue');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(80, 2, 'Décembre', 'Juillet', 'Août', 'Juin');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(81, 2, 'Ventilateur', 'Chauffage', 'Cheminée', 'Poêle');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(82, 2, 'Ballon de Rugby', 'Ballon de Handball', 'Ballon de Football', 'Ballon de Basketball');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(83, 2, 'Finir', 'Démarrer', 'Débuter', 'Commencer');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(84, 2, 'Salade', 'Mangue', 'Passion', 'Pomme');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(85, 2, 'Prendre', 'Avoir', 'Détenir', 'Posséder');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(86, 2, 'Thermomètre', 'Montre', 'Horloge', 'Cadran solaire');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(87, 2, 'Poney', 'Poisson', 'Requin', 'Dauphin');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(88, 2, 'Train', 'Paquebot', 'Navire', 'Voilier');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(89, 2, 'Voiture', 'Avion', 'Hélicoptère', 'Mongolfière');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(90, 2, 'Avion', 'Voiture', 'Camion', 'Train');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(91, 2, 'Ralentir', 'Baisser', 'Descendre', 'Diminuer');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(92, 2, 'Foulard', 'Sopalin', 'Mouchoir', 'Serviette');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(93, 2, 'Tirroir', 'Sac', 'Besace', 'Cartable');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(94, 2, 'Kilomètre', 'Heure', 'Minute', 'Seconde');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(95, 2, 'Rendez-vous', 'Calendrier', 'Agenda', 'Planning');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(96, 2, 'Percolateur', 'Spatule', 'Cuillère', 'Louche');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(97, 2, 'Marteau', 'Couteau', 'Ciseaux', 'Hâche');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(98, 2, 'Sable', 'Verre', 'Plastique', 'Papier');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(99, 2, 'Prise', 'Interrupteur', 'Bouton', 'Manette');");
    query.exec("INSERT INTO [PROPOSITIONS] VALUES(100, 2, 'Amour', 'Air', 'Eau', 'Feu');");

    query.exec("DROP TABLE IF EXISTS [USERS];");
    query.exec("CREATE TABLE [USERS] ([NAME] VARCHAR, CONSTRAINT [sqlite_autoindex_USERS_1] PRIMARY KEY ([NAME]));");

    query.exec("DROP TABLE IF EXISTS [SUIVIS];");
    query.exec("CREATE TABLE [SUIVIS] ([ID] INTEGER PRIMARY KEY, [USER_NAME] VARCHAR REFERENCES [USERS]([NAME]), [EXERCICE_ID] INTEGER REFERENCES [EXERCICES]([ID]), [NOTE] INTEGER;");

    query.exec("commit transaction;");
    query.exec("pragma foreign_keys = on;");
}
