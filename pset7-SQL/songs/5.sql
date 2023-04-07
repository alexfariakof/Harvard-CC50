-- sqlite3 songs.db
--.schema
-- cat 5.sql | sqlite3 songs.db
-- check50 cs50/labs/2023/x/songs
-- submit50 cs50/labs/2023/x/songs

/*
    Em 5.sql, escreva uma consulta SQL que retorne a energia média de todas as músicas.
        Sua consulta deve gerar uma tabela com uma única coluna e uma única linha contendo a energia média.
*/
Select AVG(energy) from songs;