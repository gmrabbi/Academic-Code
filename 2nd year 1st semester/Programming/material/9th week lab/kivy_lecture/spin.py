from kivy.app import App
from kivy.uix.widget import Widget
from kivy.properties import ObjectProperty
from kivy.lang import Builder

# Designate Our .kv design file 
Builder.load_file('spin.kv')

class HomeScreen(Widget):
	def spinner_clicked(self, value):
			self.output.text = f'You Selected: {value}'
			
class MyApp(App):
	def build(self):
		return HomeScreen()

if __name__ == '__main__':
	MyApp().run()
