#! /usr/bin/python
# -*- coding: utf-8 -*-
from scrapy import cmdline
from daily_mail import MailSender
import time
import json


def main():
    cmdline.execute('scrapy crawl dongf'.split())


if __name__ == '__main__':
    main()
