var sqlite3 = require('sqlite3').verbose();
var db = new sqlite3.Database('../../../sqlite3/warehouse.db');

db.serialize(function() {
    var stmt = db.prepare("INSERT INTO stock VALUES (?, ?, ?)");
    for (var i = 0; i < 10; i++) {
        stmt.run(i + 1, "name" + (i + 1), "category" + (i + 1));
    }
    stmt.finalize();
});

db.close();