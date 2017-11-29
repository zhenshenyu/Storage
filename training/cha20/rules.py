class Rule:
    def action(self,block,hanlder):
        hanlder.start(self.type)
        hanlder.feed(self.type)
        hanlder.end(self.type)
        return True

class HeadingRule(Rule):
    type = "heading"
    def condition(self,block):
        return not '\n' in block and len(block)<70 and not block[-1]==':'

class TitleRule(HeadingRule):
    type = 'title'
    first = True
    def condition(self,block):
        if not self.first:
            return False
        self.first = False
        return HeadingRule.condition(self,block)

class ListItemRule(Rule):
    type = 'listitem'
    def condition(self,block):
        return block[0] == '-'
    def action(self,block,hanlder):
        hanlder.start(self.type)
        hanlder.feed(block[1:].strip())
        hanlder.end(self.type)
        return True

class ListRule(ListItemRule):
    type = 'list'
    inside = False
    def condition(self,block):
        return True
    def action(self,block,hanlder):
        if not self.inside and ListItemRule.condition(self,block):
            hanlder.start(self.type)
            self.inside = True
        elif self.inside and not ListItemRule.condition(self,block):
            hanlder.end(self.type)
            self.inside = False
        return False

class ParagraphRule(Rule):
    type = 'paragraph'
    def condition(self,block):
        return True