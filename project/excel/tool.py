import xlrd

execFile = ("data.xls")
wb = xlrd.open_workbook(execFile)
sheet = wb.sheet_by_index(0)

for i in range(sheet.nrows):
    if sheet.row_values(i)[0] in ['BMO', 'Scotiabank']:
        print(sheet.row_values(i))
