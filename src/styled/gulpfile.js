const gulp = require('gulp');
const browserSync = require('browser-sync').create();

gulp.task('serve', function() {
    browserSync.init({
        server: './'
    });
    gulp.watch('./**/*.html').on('change', browserSync.reload);
});

gulp.task('default', ['serve']);
