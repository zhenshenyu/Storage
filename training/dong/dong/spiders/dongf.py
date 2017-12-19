# -*- coding: utf-8 -*-
from scrapy.spiders import BaseSpider
from dong.items import DongItem


class DongSpider(BaseSpider):
    name = 'dongf'
    start_urls = ['http://news.people.com.cn/GB/28053/']

    def parse(self, response):
        for news in response.xpath('//body/center/table[@width="761"]/tbody/tr/table[@bgcolor="d2d2d2"]'):
            try:

