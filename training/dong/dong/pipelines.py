# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html
import json
import time
import codecs
import os
import re
from scrapy.exceptions import CloseSpider


class DongPipeline(object):
    def __init__(self):
        date = time.strftime('%Y-%m-%d',time.localtime())
        self.file = codecs.open('daily_news/%s.json'% date, 'w', encoding='utf-8')
        self.file.write('[\n')

    def __del__(self):
        try:
            self.file.seek(-2, os.SEEK_END)
            self.file.truncate()
            self.file.write('\n]\n')
            self.file.close()
        except:
            pass

    def process_item(self, item, spider):
        item['title'] = re.sub('\"', '“', item['title'])
        one_new = (json.dumps(dict(item)) + ',\n').decode('unicode_escape')
        try:
            self.file.write(one_new)
        except Exception, e:
            self.file.close()
            raise CloseSpider(str(e))
        return item
