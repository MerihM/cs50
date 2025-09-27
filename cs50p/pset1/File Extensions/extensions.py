def main():
    file_name = input('File name: ').split('.')
    ext = file_name[-1].strip().lower()
    match ext:
        case 'jpg' | 'jpeg':
            print("image/jpeg")
        case 'gif' | 'png':
            print(f"image/{ext}")
        case 'pdf' | 'zip':
            print(f"application/{ext}")
        case 'txt':
            print('text/plain')
        case _:
            print('application/octet-stream')


main()
