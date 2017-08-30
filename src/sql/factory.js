var stock = require('./stock');

var sqlite3 = require('sqlite3').verbose();
var db = new sqlite3.Database('../../../sqlite3/warehouse.db');

db.serialize(function() {
    db.run("DELETE FROM stock");
    var stmt = db.prepare("INSERT INTO stock VALUES (?, ?, ?)");
    for (var i = 0; i < stock.length; i++) {
        stmt.run(i + 1, stock[i][0], stock[i][1]);
    }
    stmt.finalize();
});

db.close();