import re
from listing import *

title = True
out = open('out.html','w')
blocks = Blocks('/home/shenyu/PycharmProjects/training/cha20/listing20-1.txt')
out.write('<html><head><title>...</title><body>')
_str=''
for block in blocks:
    _str = _str + re.sub(r'\*(.+?)\*',r'<em>\1</em>',block)
    if title:
        out.write('<h1>\n'+_str+'</h1>\n')
        title = False
        _str=''
    else:
        out.write('<p>\n'+_str+'</p>')
        _str = ''
out.write('</body></html>')
out.close()