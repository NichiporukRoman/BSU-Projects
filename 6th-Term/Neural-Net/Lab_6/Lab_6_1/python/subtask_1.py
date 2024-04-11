from keras.datasets import mnist
from keras.models import Sequential
from keras.layers import Dense
from keras.src.utils import np_utils


(X_train, y_train), (X_test, y_test) = mnist.load_data()


X_train = X_train.reshape(60000, 784).astype('float32') / 255
X_test = X_test.reshape(10000, 784).astype('float32') / 255
Y_train = np_utils.to_categorical(y_train, num_classes=10)
Y_test = np_utils.to_categorical(y_test, num_classes=10)


model = Sequential()
model.add(Dense(512, activation='relu', input_shape=(784,)))
model.add(Dense(256, activation='relu'))
model.add(Dense(10, activation='softmax'))


model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])
model.fit(X_train, Y_train, validation_data=(X_test, Y_test), epochs=50, batch_size=32)


scores = model.evaluate(X_test, Y_test, verbose=0)
print("Точность работы на тестовых данных: %.2f%%" % (scores[1]*100))


model_json = model.to_json()
json_file = open("/Lab_6/Lab_6_1/models/mine/mnist_model.json", "w")
json_file.write(model_json)
json_file.close()
model.save_weights("D:/BSU-Projects/6th-Term/Neural-Net/Lab_6/Lab_6_1/models/mnist_model.h5")
