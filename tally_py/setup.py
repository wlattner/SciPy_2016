import os
from setuptools import find_packages
from distutils.core import setup, Extension


def main():
    this_dir = os.path.dirname(__file__)
    src_path = os.path.abspath(os.path.join(this_dir, "src"))

    setup(version="0.1.0",
          name="tally_py",
          ext_modules=[
              Extension(
                  "tally_py.tally_",
                  [os.path.join(src_path, "tally.c"),
                   os.path.join(src_path, "tally_module.c")])
          ],
          packages=find_packages()
          )

if __name__ == "__main__":
    main()
