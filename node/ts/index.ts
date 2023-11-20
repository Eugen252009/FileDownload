import { writeFileSync } from "fs"
const url = "https://lupricht.net/picture.jpg"
const filename = "picture.jpg"
async function main() {
	const response = await fetch(url)
	const buf = Buffer.from(await response.arrayBuffer())
	writeFileSync(filename, buf)
}
main()
