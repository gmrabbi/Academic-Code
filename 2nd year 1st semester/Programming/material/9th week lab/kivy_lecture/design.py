from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.widget import Widget
from kivy.properties import ObjectProperty
from kivy.lang import Builder

Builder.load_file('my_1.kv')

class MyGridLayout(Widget):
	
	name = ObjectProperty(None)
	pizza = ObjectProperty(None)
	color = ObjectProperty(None)

	def press(self):
		name = self.name.text
		pizza = self.pizza.text
		color = self.color.text

		self.output.text = f'Hello {name}, you like {pizza} pizza, and your favorite color is {color}!'
		self.output.font_size = 40
		# Clear the input boxes
		self.name.text = ""
		self.pizza.text = ""
		self.color.text = ""

class MyApp(App):
	def build(self):
		return MyGridLayout()
	
if __name__ == '__main__':
	MyApp().run()



