FROM alpine

RUN apk update
RUN apk add vim
RUN apk add g++

CMD ["echo", "Image pushed successfully"]
CMD ["echo", "installed linux (alpine), vim edotor and g++ compiler"]
CMD ["echo", "Enjoy"]
