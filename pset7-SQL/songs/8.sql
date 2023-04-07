-- sqlite3 songs.db
--.schema
-- cat 8.sql | sqlite3 songs.db
-- check50 cs50/labs/2023/x/songs
-- submit50 cs50/labs/2023/x/songs

/*
    Em 8.sql, escreva uma consulta SQL que liste os nomes das músicas que apresentam outros artistas.
    As músicas que apresentam outros artistas incluirão “feat.” em nome da música.
    Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
*/

Select s.name from songs s inner join artists a on s.artist_id = a.id where s.name like '%feat.%';