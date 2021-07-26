#!/bin/sh

cppcheck . \
    --enable=yep \
    --error-exitcode=255
