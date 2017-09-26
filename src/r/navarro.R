# Chapter 4
exists("read.spss")

# 4.4.4 Navigating the ﬁle system using the Rstudio ﬁle panel
setwd("G:\\github\\reading-list\\src\\r")

# 4.5.3 Importing data from CSV ﬁles using R
cats <- read.csv(file = "./cats.csv")

View(cats)