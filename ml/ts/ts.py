import tensorflow as tf


def test():
    hello = tf.constant('Hello, TensorFlow!')
    sess = tf.Session()
    print(sess.run(hello))


if __name__ == '__main__':
    test()
