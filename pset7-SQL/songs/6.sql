-- sqlite3 songs.db
--.schema
-- cat 6.sql | sqlite3 songs.db
-- check50 cs50/labs/2023/x/songs
-- submit50 cs50/labs/2023/x/songs

/*
    Em 6.sql, escreva uma consulta SQL que liste os nomes das músicas de Post Malone.
    Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
    Você não deve fazer suposições sobre o que artist_idé o Post Malone.
*/

Select s.name from songs s inner join artists a on s.artist_id = a.id where a.name like 'Post Malone';