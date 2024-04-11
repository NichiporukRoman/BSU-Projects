import numpy
from keras.models import model_from_json
from keras.datasets import mnist
from PIL import Image
from tensorflow.python.keras.utils import np_utils


json_filename = "D:/BSU-Projects/6th-Term/Neural-Net/Lab_6/Lab_6_1/models/provided/mnist_model.json"
with open(json_filename, "r") as json_file:
    loaded_model_json = json_file.read()

model = model_from_json(loaded_model_json)

h5_filename = "D:/BSU-Projects/6th-Term/Neural-Net/Lab_6/Lab_6_1/models/provided/mnist_model.h5"
model.load_weights(h5_filename)

model.compile(loss="categorical_crossentropy", optimizer="SGD", 
              metrics=["accuracy"])

print(model.summary())
_, (x_test, y_test) = mnist.load_data()
X_test = x_test.reshape(10000, 784)
X_test = X_test.astype('float32')
X_test /= 255
Y_test = np_utils.to_categorical(y_test, 10)


scores = model.evaluate(X_test, Y_test, verbose=0)
print("Точность работы на тестовых данных : %.2f%%" % (scores[1] * 100))

pic_name = "D:/BSU-Projects/6th-Term/Neural-Net/Lab_6/Lab_6_1/data/7.png"
img = Image.open(pic_name)

arr = numpy.array(img)
new_arr = numpy.array([
        [255 - pixel[0] for row in arr for pixel in row]
        ], 'float32')

new_arr /= 255

result = model.predict(new_arr)
for i, perc in enumerate(numpy.round(100 * result)[0]):
    print("%d: %d%%" % (i, perc))
print("result = %d" % numpy.argmax(result))
